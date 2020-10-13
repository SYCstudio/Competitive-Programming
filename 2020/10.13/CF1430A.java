import java.util.Scanner;

public class CF1430A{
    static int record[]=new int[1001];
    static int ra[]=new int[1001],rb[]=new int[1001];
    public static void main(String argc[]){
        for (int i=0;i*5<=1000;i++)
            for (int j=0;j*3+i*5<=1000;j++){
                record[i*5+j*3]=1;
                ra[i*5+j*3]=j;
                rb[i*5+j*3]=i;
            }
        
        Scanner Input=new Scanner(System.in);
        int Case=Input.nextInt();
        while (Case-->0){
            int n=Input.nextInt();
            boolean flag=false;
            for (int i=0;i*7<=n;i++)
                if (record[n-i*7]==1){
                    System.out.println(ra[n-i*7]+" "+rb[n-i*7]+" "+i);
                    flag=true;break;
                }
            if (flag==false) System.out.println(-1);
        }
        return;
    }
}