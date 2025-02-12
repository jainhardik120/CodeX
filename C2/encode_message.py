import cv2

image = cv2.imread('image.jpg')
modified_image = image.copy()

print(image.shape)

height, width = image.shape[:2]

for x in range(width):
    for y in range(height):
        r, g, b = image[x, y]


        modified_r = r + 50
        modified_g = g
        modified_b = b

        if modified_r > 255:
            modified_r = 255
        if modified_g > 255:
            modified_g = 255
        if modified_b > 255:
            modified_b = 255

        modified_image[x, y] = (modified_r, modified_g, modified_b)

cv2.imwrite('modified_image.jpg', modified_image)