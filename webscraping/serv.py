from flask import Flask, request, jsonify
from PIL import Image
import pytesseract

app = Flask(__name__)

# Endpoint for uploading and processing images
@app.route('/process_image', methods=['POST'])
def process_image():
    try:
        # Check if an image file is uploaded
        if 'image' not in request.files:
            return jsonify({'error': 'No image provided'}), 400

        image_file = request.files['image']

        # Check if the file has an allowed extension (e.g., '.jpg', '.png')
        if not image_file.filename.endswith(('.jpg', '.jpeg', '.png')):
            return jsonify({'error': 'Invalid file format'}), 400

        # Open and process the image using Tesseract OCR
        image = Image.open(image_file)
        license_plate = pytesseract.image_to_string(image)

        return jsonify({'license_plate': license_plate.strip()})
    
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True)
