import java.security.MessageDigest;
import java.io.UnsupportedEncodingException;

public class Main {
    private static final String chainXor(String s1,String s2){
        int len = Math.min(s1.length(), s2.length());
        char[] src = len == s1.length() ? s1.toCharArray() : s2.toCharArray();
        StringBuilder sb = new StringBuilder();
        
        char c = (char) ((len ^ src[0]) % 26 + 97);
        sb.append(c);

        for (int i = 1; i < len; i++){
            c = (char)((c ^ src[i]) % 26 + 97);
            sb.append(c);
        }
        return sb.toString();
    }

    /**
     * 小写字母表
     */
    static String xor (String s1,String s2) {
        if(s1.isEmpty() || s2.isEmpty()){
            return "";
        }
        int len = Math.min(s1.length(), s2.length());

        char[] cArr1 = s1.toCharArray();
        char[] cArr2 = s2.toCharArray();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++){
           sb.append ((char) ((cArr1[i] ^ cArr2[i]) % 26 + 97));
        }
        return sb.toString();
     }
     
      /**
      * ASCII 表
      * @param s1
      * @param s2
      * @return
      */
     static String axor(String s1, String s2){
        char[] cArr1 = s1.toCharArray();
        char[] cArr2 = s2.toCharArray();
        int len = Math.min(s1.length(),s2.length());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < len; i++){
           char c = (char) ((cArr1[i] ^ cArr2[i]) % 127 + 1);
           sb.append(c);
        }
        return sb.toString();
     }

    public static void main(String[] args) {

    /* 
    04-27 14:42:54.599 14901-14901/com.bcoin.nl E/main: token: 6e4069678612b2f5b54e28be184967ab
    04-27 14:42:54.599 14901-14901/com.bcoin.nl E/main: payload: getUserAccountInfoBySecretNew
    04-27 14:42:54.599 14901-14901/com.bcoin.nl D/bc: 626f9dc1cc2752dee9d2c2cd9bbbdd20:b 
    */

      /*   String c1 = "getUserAccountInfoBySecretNew";
        String c2 = "6e4069678612b2f5b54e28be184967ab";

        System.out.println("======== chain xor =========");
        String rtn  = chainXor(c1, c2);
        System.out.printf("返回的数据为：%s\n",rtn);

        System.out.println("======== xor =========");
        rtn  = xor(c1, c2);
        System.out.printf("length of data is: %d\n",rtn.length());
        System.out.printf("返回的数据为：%s\n",rtn);
        
        System.out.println("======== axor =========");
        char [] c = axor(c1,c2).toCharArray();
        for(int i =0; i<c.length;i++){
            int val = (short)c[i];
            System.out.println(val);
        } */


        testXor();
    }

    private static String token = "6e4069678612b2f5b54e28be184967ab";
    private static String payload = "getUserAccountInfoBySecretNew";


    private static void testXor() {

    /* 
    04-27 14:42:54.599 14901-14901/com.bcoin.nl E/main: token: 6e4069678612b2f5b54e28be184967ab
    04-27 14:42:54.599 14901-14901/com.bcoin.nl E/main: payload: getUserAccountInfoBySecretNew
    04-27 14:42:54.599 14901-14901/com.bcoin.nl D/bc: 626f9dc1cc2752dee9d2c2cd9bbbdd20:b 
    */

    System.out.println("======== xor test =========");
    String rtn  = xor(payload, token);
    System.out.printf("length of data is: %d\n",rtn.length());
    System.out.printf("返回的数据为：%s\n",rtn);
    
    

    System.out.print("生成的MD5数据为：");

    try{
        rtn = md5(rtn.getBytes());
        System.out.println(rtn);
    }catch(Exception e){

    }

    String fuc = "b" + rtn;
    System.out.printf("加入算法后的数据为：%s\n",fuc);

    }



    private static String md5(byte[] bytes){
        try{
            MessageDigest m = MessageDigest.getInstance("MD5");
            m.update(bytes);
            byte s[] = m.digest();
            String result = "";
            for (int i = 0; i < s.length; i++) {
                result += Integer.toHexString((0x000000FF & s[i]) | 0xFFFFFF00).substring(6);
            }
            return result;
        }catch(Exception e){
            e.printStackTrace();
        }
        return null;
    }
}
