import numpy as np
from PIL import Image

image_path = "sample.jpg"
img = Image.open(image_path)
img_array = np.array(img)

print(f"Image shape: {img_array.shape}")
print(f"Image data type: {img_array.dtype}")

red = img_array[:, :, 0]
green = img_array[:, :, 1]
blue = img_array[:, :, 2]

res = np.dstack(
    (red, np.zeros(red.shape), np.full(red.shape, 0), green)).astype(np.uint8)

print(res.shape)

new_image = Image.fromarray(res)
new_image.save("new.png")
