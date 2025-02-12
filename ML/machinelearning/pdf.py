#%%
from pdfquery import PDFQuery

pdf = PDFQuery("studentMarks.pdf")

#%%

pdf.load()
# %%
text_elements = pdf.pq('LTTextBoxHorizontal')
text = [t.text for t in text_elements]
for t in text:
    print(t)


# %%
pdf.tree.write('marks.xml', pretty_print=True)
pdf


# %%
page = pdf.get_page(page_number=0)


# %%
