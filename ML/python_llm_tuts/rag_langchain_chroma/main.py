import os
from dotenv import load_dotenv
import shutil

# Google AI libraries
import google.generativeai as genai
from google.generativeai.types import HarmCategory, HarmBlockThreshold

# LangChain dependencies
from langchain.document_loaders.pdf import PyPDFDirectoryLoader
from langchain.text_splitter import RecursiveCharacterTextSplitter
from langchain.schema import Document
from langchain.vectorstores.chroma import Chroma
from langchain.prompts import ChatPromptTemplate

# Load environment variables
load_dotenv()

# Configure Google AI API
genai.configure(api_key=os.getenv('GOOGLE_API_KEY'))

# Path configurations
DATA_PATH = "."
CHROMA_PATH = "chromadb"

class GeminiEmbeddings:
    """Custom Embedding class to work with Gemini embeddings in LangChain"""
    def __init__(self, model_name='models/embedding-004'):
        self.model = model_name
    
    def embed_documents(self, texts):
        """Embed a list of documents"""
        return [self.embed_query(text) for text in texts]
    
    def embed_query(self, text):
        """Embed a single query"""
        embedding = genai.embed_content(
            model=self.model,
            content=text,
            task_type="retrieval_document"
        )
        return embedding['embedding']

def load_documents():
    """
    Load PDF documents from the specified directory using PyPDFDirectoryLoader.
    Returns:
    List of Document objects: Loaded PDF documents
    """
    document_loader = PyPDFDirectoryLoader(DATA_PATH) 
    return document_loader.load() 

def split_text(documents: list[Document]):
    """
    Split the text content of the given list of Document objects into smaller chunks.
    """
    text_splitter = RecursiveCharacterTextSplitter(
        chunk_size=300,
        chunk_overlap=100,
        length_function=len,
        add_start_index=True,
    )

    chunks = text_splitter.split_documents(documents)
    print(f"Split {len(documents)} documents into {len(chunks)} chunks.")

    return chunks

def save_to_chroma(chunks: list[Document]):
    """
    Save the given list of Document objects to a Chroma database using Gemini embeddings.
    """
    # Clear out the existing database directory if it exists
    if os.path.exists(CHROMA_PATH):
        shutil.rmtree(CHROMA_PATH)

    # Create a new Chroma database from the documents using Gemini embeddings
    db = Chroma.from_documents(
        chunks,
        GeminiEmbeddings(),
        persist_directory=CHROMA_PATH
    )

    # Persist the database to disk
    db.persist()
    print(f"Saved {len(chunks)} chunks to {CHROMA_PATH}.")

def generate_data_store():
    """
    Function to generate vector database in chroma from documents.
    """
    documents = load_documents()
    chunks = split_text(documents)
    save_to_chroma(chunks)

def query_rag(query_text):
    """
    Query a Retrieval-Augmented Generation (RAG) system using Chroma database and Gemini.
    """
    # Use the same embedding function as before
    embedding_function = GeminiEmbeddings()

    # Prepare the database
    db = Chroma(persist_directory=CHROMA_PATH, embedding_function=embedding_function)
    
    # Retrieving the context from the DB using similarity search
    results = db.similarity_search_with_relevance_scores(query_text, k=3)

    # Check if there are any matching results or if the relevance score is too low
    if len(results) == 0 or results[0][1] < 0.7:
        print(f"Unable to find matching results.")
        return None

    # Combine context from matching documents
    context_text = "\n\n - -\n\n".join([doc.page_content for doc, _score in results])
 
    # Prepare prompt template
    PROMPT_TEMPLATE = """
    Answer the question based only on the following context:
    {context}
     - -
    Answer the question based on the above context: {question}
    """

    # Prepare the full prompt
    full_prompt = PROMPT_TEMPLATE.format(context=context_text, question=query_text)

    # Initialize Gemini model with safety settings
    model = genai.GenerativeModel(
        'gemini-pro',
        generation_config={
            "temperature": 0.7,
            "max_output_tokens": 2048
        },
        safety_settings={
            HarmCategory.HARM_CATEGORY_HATE_SPEECH: HarmBlockThreshold.BLOCK_MEDIUM_AND_ABOVE,
            HarmCategory.HARM_CATEGORY_HARASSMENT: HarmBlockThreshold.BLOCK_MEDIUM_AND_ABOVE,
        }
    )

    # Generate response
    response = model.generate_content(full_prompt)
 
    # Get sources of the matching documents
    sources = [doc.metadata.get("source", None) for doc, _score in results]
 
    # Format and return response
    formatted_response = f"Response: {response.text}\nSources: {sources}"
    return formatted_response

def main():
    # Generate the data store (only needs to be run once)
    generate_data_store()

    # Example query
    query_text = "Explain how the YOLO method works"
    result = query_rag(query_text)
    
    if result:
        print(result)

if __name__ == "__main__":
    main()