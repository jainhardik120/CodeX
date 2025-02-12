import javax.crypto.Cipher;
import java.security.*;
import javax.crypto.*;
import java.io.UnsupportedEncodingException;
import java.util.Base64;

public class AsymmetricCryptoWithUserInput {
    private static final String KEY_ALGORITHM = "RSA";
    private static final String CIPHER_ALGORITHM = "RSA/ECB/PKCS1Padding";
    private static final int KEY_SIZE = 2048;
    
    public static KeyPair generateKeyPair(String userPassword) throws NoSuchAlgorithmException, NoSuchProviderException {
        SecureRandom secureRandom = SecureRandom.getInstance("SHA1PRNG");
        secureRandom.setSeed(userPassword.getBytes());
        
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance(KEY_ALGORITHM);
        keyGen.initialize(KEY_SIZE, secureRandom);
        
        return keyGen.generateKeyPair();
    }
    
    public static String encrypt(String plaintext, PublicKey publicKey) throws NoSuchAlgorithmException, NoSuchPaddingException, IllegalBlockSizeException, BadPaddingException,InvalidKeyException; {
        Cipher cipher = Cipher.getInstance(CIPHER_ALGORITHM);
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedBytes = cipher.doFinal(plaintext.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }
    
    public static String decrypt(String ciphertext, PrivateKey privateKey) throws NoSuchAlgorithmException, NoSuchPaddingException, IllegalBlockSizeException, BadPaddingException, UnsupportedEncodingException ,InvalidKeyException;{
        Cipher cipher = Cipher.getInstance(CIPHER_ALGORITHM);
        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decodedCiphertext = Base64.getDecoder().decode(ciphertext);
        byte[] decryptedBytes = cipher.doFinal(decodedCiphertext);
        return new String(decryptedBytes, "UTF-8");
    }
    
    public static void main(String[] args) {
        try {
            String userPassword = "UserInputPassphrase";
            KeyPair keyPair = generateKeyPair(userPassword);
            PublicKey publicKey = keyPair.getPublic();
            PrivateKey privateKey = keyPair.getPrivate();

            String plaintext = "Hello, this is a message encrypted with asymmetric cryptography!";

            String ciphertext = encrypt(plaintext, publicKey);

            String decryptedText = decrypt(ciphertext, privateKey);

            System.out.println("Plaintext: " + plaintext);
            System.out.println("Ciphertext: " + ciphertext);
            System.out.println("Decrypted Text: " + decryptedText);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
