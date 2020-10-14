#include<bits/stdc++.h>
using namespace std;

const int maxN=202000;

int n;
priority_queue<int> Heap;
pair<int,int> Ans[maxN];

int main(){
    int Case;scanf("%d",&Case);
    while (Case--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) Heap.push(i);
        int tot=0;
        while (Heap.size()>=2){
            int t1=Heap.top();Heap.pop();
            int t2=Heap.top();Heap.pop();
            Ans[++tot]=make_pair(t1,t2);
            Heap.push((t1+t2+1)/2);
        }
        printf("%d\n",Heap.top());Heap.pop();
        for (int i=1;i<=tot;i++) printf("%d %d\n",Ans[i].first,Ans[i].second);
    }
    return 0;
}