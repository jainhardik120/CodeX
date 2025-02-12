from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
import os

# Generate a random 256-bit key
key = os.urandom(32)
iv = os.urandom(16)
# Message
plaintext = "This is a secret message."
# Pad the message
padder = padding.PKCS7(128).padder()
padded_data = padder.update(plaintext.encode()) + padder.finalize()
# Create AES CBC cipher for encryption
cipher_encrypt = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
encryptor = cipher_encrypt.encryptor()
ciphertext = encryptor.update(padded_data) + encryptor.finalize()
print(f"Ciphertext: {ciphertext.hex()}")
# Create AES CBC cipher for decryption
cipher_decrypt = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())

decryptor = cipher_decrypt.decryptor()
decrypted_padded_data = decryptor.update(ciphertext) + decryptor.finalize()
# Unpad the decrypted message
unpadder = padding.PKCS7(128).unpadder()
decrypted_data = unpadder.update(decrypted_padded_data) + unpadder.finalize()
print(f"Decrypted Text: {decrypted_data.decode()}")
