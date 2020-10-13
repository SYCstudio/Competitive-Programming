import java.util.Scanner;
import java.util.Arrays;

public class CF1430B {
    public static void main(String argc[]){
        Scanner Input=new Scanner(System.in);

        int Case=Input.nextInt();
        while (Case>0){
            int n=Input.nextInt(),K=Input.nextInt();
            int num[]=new int[n];
            for (int i=0;i<n;i++) num[i]=Input.nextInt();
            Arrays.sort(num);
            long sum=0;
            for (int i=n-K;i<=n;i++) sum=sum+num[i-1];

            System.out.println(sum);
            --Case;
        }
        return;
    }
}
