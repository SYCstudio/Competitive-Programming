import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Comparator;

public class CF1430C{
    static int maxN=202000;
    static PriorityQueue<Integer> Heap=new PriorityQueue<Integer>(maxN,new Comparator<Integer>(){
        @Override
        public int compare(Integer o1,Integer o2){
            return o2.compareTo(o1);
        }
    });
    //*/
    static int A1[]=new int[maxN],A2[]=new int[maxN];
    static public void main(String argc[]){
        Scanner Input=new Scanner(System.in);

        int Case=Input.nextInt();
        while (Case-->0){
            int n=Input.nextInt();
            for (int i=1;i<=n;i++) Heap.add(i);

            int tot=0;
            while (Heap.size()>=2){
                int t1=Heap.poll(),t2=Heap.poll();++tot;
                A1[tot]=t1;A2[tot]=t2;
                Heap.add((t1+t2+1)/2);
            }

            System.out.println(Heap.poll());
            for (int i=1;i<=tot;i++) System.out.println(A1[i]+" "+A2[i]);
        }
        return;
    }
}