from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
def des_encrypt(plaintext: str, key: bytes) -> bytes:
    cipher = Cipher(algorithms.DES(key), modes.ECB(), backend=default_backend())
    encryptor = cipher.encryptor()
    return encryptor.update(plaintext.encode()) + encryptor.finalize()
def des_decrypt(ciphertext: bytes, key: bytes) -> str:
    cipher = Cipher(algorithms.DES(key), modes.ECB(), backend=default_backend())
    decryptor = cipher.decryptor()
    return decryptor.update(ciphertext).decode()