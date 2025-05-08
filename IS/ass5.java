import java.security.*;
import javax.crypto.Cipher;
import java.util.Base64;

class ass5 {
    public static void main(String[] args) throws Exception {
        // Generate RSA Key Pair
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
        keyGen.initialize(2048); // You can use 1024, 2048, or 4096 bits
        KeyPair pair = keyGen.generateKeyPair();
        PublicKey publicKey = pair.getPublic();
        PrivateKey privateKey = pair.getPrivate();

        // Plain text message
        String message = "Message to encrypt";
        System.out.println("Original Message: " + message);

        // Encrypt the message using the public key
        Cipher encryptCipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        encryptCipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedBytes = encryptCipher.doFinal(message.getBytes());
        String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);
        System.out.println("Encrypted Text: " + encryptedText);

        // Decrypt the message using the private key
        Cipher decryptCipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        decryptCipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decryptedBytes = decryptCipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);
        System.out.println("Decrypted Text: " + decryptedText);
    }
}
