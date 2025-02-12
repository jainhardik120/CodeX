import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class AES {

    public static void main(String[] args) throws Exception {
        SecretKey secretKey = generateAESKey();

        String plainText = "Hey, this is Hardik Jain";
        String keyBase64 = Base64.getEncoder().encodeToString(secretKey.getEncoded());
        System.out.println("AES Key is: \n" + keyBase64);

        String encryptedText = encryptAES(plainText, secretKey);
        System.out.println("Encrypted Message: \n" + encryptedText);

        String decryptedText = decryptAES(encryptedText, secretKey);
        System.out.println("Decrypted Message: \n" + decryptedText);
    }

    public static SecretKey generateAESKey() throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("AES");
        keyGenerator.init(256); 
        return keyGenerator.generateKey();
    }

    public static String encryptAES(String plainText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(plainText.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    public static String decryptAES(String encryptedText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedText);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        return new String(decryptedBytes);
    }
}
