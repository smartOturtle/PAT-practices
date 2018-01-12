import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        String s=in.next();
        BigInteger num=new BigInteger(s);
        int maxStep=in.nextInt();
        int step=0;
        while(true){
            boolean isPalindromic=true;
            for (int i=0;i<s.length()/2;i++){
                if(s.charAt(i)!=s.charAt(s.length()-1-i)){
                    isPalindromic=false;
                    break;
                }
            }
            if(isPalindromic)break;
            StringBuilder sb=new StringBuilder(s);
            BigInteger reverse=new BigInteger(sb.reverse().toString());
            num=num.add(reverse);
            s=num.toString();
            if(++step>=maxStep)break;
        }
        System.out.println(s);
        System.out.println(step);
    }
}
