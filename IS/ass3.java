import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.KeyGenerator;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

class ass3 {
    public static void main(String[] args) throws Exception {
        String plainText = "Namaste India";

        KeyGenerator keyGen = KeyGenerator.getInstance("DES");
        SecretKey secretKey = keyGen.generateKey();

        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");

        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(plainText.getBytes());
        String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);
        System.out.println("Encrypted Text: " + encryptedText);

        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);
        System.out.println("Decrypted Text: " + decryptedText);
    }
}
