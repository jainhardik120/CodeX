from PIL import Image

img = Image.open("image.jpg")
pixels = img.load()

for i in range(img.height):
    for j in range(img.width):
        r,g,b = pixels[i,j]
        pixels[i,j] = (r,g,b)

img.save("output.jpg")