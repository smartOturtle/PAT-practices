import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static boolean isPalindromic(String s){
        if(s.length()%2==1)
        {
            int middle = s.length() / 2;
            for (int i = 1; middle>=i; ++i)
                if (s.charAt(middle - i) != s.charAt(middle + i))return false;
        }
        else
        {
            int leftMid = s.length() / 2 - 1, rightMid = s.length() / 2;
            for (int i = 0; leftMid>=i; ++i)
                if (s.charAt(leftMid - i) != s.charAt(rightMid + i))return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String s=in.next();
        for (int i = 0; i < 10&&!isPalindromic(s); i++) {
            BigInteger num=new BigInteger(s);
            BigInteger reverseNum=new BigInteger(new StringBuilder(s).reverse().toString());
            s=num.add(reverseNum).toString();
            System.out.println(num+" + "+reverseNum+" = "+s);
        }
        if(isPalindromic(s))System.out.println(s+" is a palindromic number.");
        else System.out.println("Not found in 10 iterations.");
    }
}
