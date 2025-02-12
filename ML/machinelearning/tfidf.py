# # import required module
# from sklearn.feature_extraction.text import TfidfVectorizer

# # assign documents
# d0 = 'Geeks for geeks'
# d1 = 'Geeks'
# d2 = 'r2j'

# # merge documents into a single corpus
# string = [d0, d1, d2]

# # create object
# tfidf = TfidfVectorizer()

# # get tf-df values
# result = tfidf.fit_transform(string)

# print(tfidf.idf_)


# # get idf values
# print('\nidf values:')
# for ele1, ele2 in zip(tfidf.get_feature_names_out(), tfidf.idf_):
# 	print(ele1, ':', ele2)

# # get indexing
# print('\nWord indexes:')
# print(tfidf.vocabulary_)

# # display tf-idf values
# print('\ntf-idf value:')
# print(result)

# # in matrix form
# print('\ntf-idf values in matrix form:')
# print(result.toarray())

from sklearn.feature_extraction.text import TfidfVectorizer
corpus = [
    'This is the first document.',
    'This document is the second document.',
    'And this is the third one.',
    'Is this the first document?',
]
vectorizer = TfidfVectorizer()
X = vectorizer.fit_transform(corpus)
print(vectorizer.get_feature_names_out())
print(X.toarray());