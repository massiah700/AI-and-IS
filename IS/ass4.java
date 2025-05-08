import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

class ass4 {
    public static void main(String[] args) throws Exception {
        String key = "C1pherK3y70xxxx"; // Adjust the key length to 16, 24, or 32 bytes
        String data = "AES encryption";

        // Ensure key length is exactly 16 bytes
        byte[] keyBytes = key.getBytes();
        byte[] truncatedKey = new byte[16];
        System.arraycopy(keyBytes, 0, truncatedKey, 0, Math.min(keyBytes.length, 16));
        SecretKeySpec skeySpec = new SecretKeySpec(truncatedKey, "AES");

        Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");

        // Encryption
        cipher.init(Cipher.ENCRYPT_MODE, skeySpec);
        byte[] encrypted = cipher.doFinal(data.getBytes());
        System.out.println("Encrypted: " + Base64.getEncoder().encodeToString(encrypted));

        // Decryption
        cipher.init(Cipher.DECRYPT_MODE, skeySpec);
        byte[] decrypted = cipher.doFinal(encrypted);
        System.out.println("Decrypted: " + new String(decrypted));
    }
}
