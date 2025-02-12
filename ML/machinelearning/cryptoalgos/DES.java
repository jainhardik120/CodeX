import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESKeySpec;
import java.util.Base64;

public class DES {

    public static void main(String[] args) throws Exception {
        SecretKey secretKey = generateDESKey();

        String plainText = "Hey, this is Hardik Jain";
        String keyBase64 = Base64.getEncoder().encodeToString(secretKey.getEncoded());
        System.out.println("DES Key is: \n" + keyBase64);

        String encryptedText = encryptDES(plainText, secretKey);
        System.out.println("Encrypted Message: \n" + encryptedText);

        String decryptedText = decryptDES(encryptedText, secretKey);
        System.out.println("Decrypted Message: \n" + decryptedText);
    }

    public static SecretKey generateDESKey() throws Exception {
        byte[] keyBytes = "12345678".getBytes();
        DESKeySpec keySpec = new DESKeySpec(keyBytes);
        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("DES");
        return keyFactory.generateSecret(keySpec);
    }

    public static String encryptDES(String plainText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(plainText.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    public static String decryptDES(String encryptedText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedText);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        return new String(decryptedBytes);
    }
}
