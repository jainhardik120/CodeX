import java.security.*;
import javax.crypto.*;

public class KeyPairGenertor {
   public static void main(String[] args) throws Exception {
        // Step 1: Generate Key Pair
        KeyPair keyPair = generateKeyPair();

        // Step 2: Print the Private Key (Note: This is just for demonstration purposes. In a real-world scenario,
        // you should handle the private key securely, like storing it in a keystore or a secure database).
        PrivateKey privateKey = keyPair.getPrivate();
        System.out.println("Private Key: " + bytesToHex(privateKey.getEncoded()));

        // Step 3: Encrypt Data
        String dataToEncrypt = "Hello, this is a secret message!";
        byte[] encryptedData = encryptData(dataToEncrypt, keyPair.getPublic());

        // Step 4: Decrypt Data
        String decryptedData = decryptData(encryptedData, privateKey);
        System.out.println("Decrypted Data: " + decryptedData);
    }

    // Helper method to generate a Key Pair
    private static KeyPair generateKeyPair() throws NoSuchAlgorithmException {
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
        keyGen.initialize(2048); // You can change the key size as needed
        return keyGen.generateKeyPair();
    }

    // Helper method to encrypt data using the public key
    private static byte[] encryptData(String data, PublicKey publicKey) throws Exception {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        return cipher.doFinal(data.getBytes());
    }

    // Helper method to decrypt data using the private key
    private static String decryptData(byte[] encryptedData, PrivateKey privateKey) throws Exception {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decryptedBytes = cipher.doFinal(encryptedData);
        return new String(decryptedBytes);
    }

    // Helper method to convert bytes to hex string for printing the private key
    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02X", b));
        }
        return result.toString();
    }
}