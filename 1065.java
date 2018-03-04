import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int caseCnt=in.nextInt();
        for (int i = 0; i < caseCnt; i++) {
            String a=in.next();
            String b=in.next();
            String c=in.next();
            BigInteger aInt=new BigInteger(a);
            BigInteger bInt=new BigInteger(b);
            BigInteger cInt=new BigInteger(c);
            System.out.print("Case #"+(i+1)+": ");
            if(aInt.add(bInt).compareTo(cInt)>0) System.out.println("true");
            else System.out.println("false");
        }
    }
}
