import requests

from bs4 import BeautifulSoup

# def saveToFile(url, path):
#     r = requests.get(url)
#     with open(path , "w", encoding="utf-8") as f:
#         f.write(r.text)

# saveToFile("https://www.jiit.ac.in/", "data/times.html")


with open("data/times.html", "r", encoding="utf-8") as f:
    html_doc = f.read()
soup = BeautifulSoup(html_doc, 'html.parser')


print(soup.prettify())
print(soup.title.string)
print(soup.find_all("div")[2])

with open("data/links.txt", "w") as f:
    for link in soup.find_all("a"):
        # print(link.get("href"))
        # f.write(link.get("href"))
        print(link.get("href"))
        f.write(link.get("href") + "\n")
