from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import rsa, padding

# Generate an RSA private key
private_key = rsa.generate_private_key(
    public_exponent=65537, key_size=2048, backend=default_backend()
)
# Derive the public key
public_key = private_key.public_key()
# Message
plaintext = "This is another secret message."
# Encrypt the message using public key
ciphertext = public_key.encrypt(
    plaintext.encode(),
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None,
    ),
)
print(f"Ciphertext: {ciphertext.hex()}")
# Decrypt the message using private key
decrypted_text = private_key.decrypt(
    ciphertext,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None,
    ),
)
print(f"Decrypted Text: {decrypted_text.decode()}")
