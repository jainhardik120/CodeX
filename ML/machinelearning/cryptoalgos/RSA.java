import java.security.*;
import javax.crypto.Cipher;
import java.util.Base64;

public class RSA {

    public static void main(String[] args) throws Exception {
        KeyPair keyPair = generateKeyPair();

        String plainText = "Hello, RSA Encryption!";
        String keyPublic = bytesToHex(keyPair.getPublic().getEncoded());
        String keyPrivate = bytesToHex(keyPair.getPrivate().getEncoded());
        System.out.println("Public Key is : \n" + keyPublic);
        System.out.println("Private Key is : \n" + keyPrivate);

        String base64Public = Base64.getEncoder().encodeToString(keyPair.getPublic().getEncoded());
        String base64Private = Base64.getEncoder().encodeToString(keyPair.getPrivate().getEncoded());

        System.out.println("Public Key is : \n" + base64Public);
        System.out.println("Private Key is : \n" + base64Private);

        String encryptedText = encrypt(plainText, keyPair.getPublic());
        System.out.println("Encrypted Message: \n" + encryptedText);

        String decryptedText = decrypt(encryptedText, keyPair.getPrivate());
        System.out.println("Decrypted Message: \n" + decryptedText);
    }

    public static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder(2 * bytes.length);
        for (byte b : bytes) {
            hexString.append(String.format("%02x", b));
        }
        return hexString.toString();
    }

    public static KeyPair generateKeyPair() throws Exception {
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator.initialize(2048); 
        return keyPairGenerator.generateKeyPair();
    }

    public static String encrypt(String plainText, PublicKey publicKey) throws Exception {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedBytes = cipher.doFinal(plainText.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    public static String decrypt(String encryptedText, PrivateKey privateKey) throws Exception {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedText);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        return new String(decryptedBytes);
    }
}
