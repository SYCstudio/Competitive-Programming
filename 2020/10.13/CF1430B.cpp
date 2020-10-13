#include<bits/stdc++.h>
using namespace std;

const int maxN=201000;

int n,K;
int num[maxN];

int main(){
    int Case;
    scanf("%d",&Case);
    while (Case--){
        scanf("%d%d",&n,&K);
        for (int i=1;i<=n;i++) scanf("%d",&num[i]);
        sort(&num[1],&num[n+1]);
        long long ans=0;
        for (int i=n-K;i<=n;i++) ans=ans+num[i];
        printf("%lld\n",ans);
    }
    return 0;
}