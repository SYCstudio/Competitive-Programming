#include<bits/stdc++.h>
using namespace std;

#define Max(a,b) a=max(a,b)
typedef long long ll;

const int maxN=52;
const int inf=2000000000;
const ll INF=1e16;
const int Log=35;
const int maxK=350;

class Festival{
    public:
    int time,pos,val;
};
class Matrix{
    public:
    ll M[maxN*5][maxN*5];
    void init();
    void outp();
};

int n,m,K,T,SIZE;
int Val[maxN];
Festival Fl[maxK];
Matrix Ans,B[Log],Bp;

bool operator < (Festival A,Festival B);
Matrix operator * (Matrix A,Matrix B);
void Mul(int opt);

int main(){
    freopen("delicacy.in","r",stdin);
    freopen("delicacy.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&T,&K);SIZE=n*5;
    for (int i=1;i<=n;i++) scanf("%d",&Val[i]);

    Ans.init();B[0].init();Ans.M[1][1]=Val[1];
    for (int i=1;i<=n;i++) B[0].M[i+n][i]=Val[i];
    for (int t=2;t<=4;t++) for (int i=1;i<=n;i++) B[0].M[i+t*n][i+t*n-n]=0;

    for (int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        if (w==1) Max(B[0].M[u][v],1ll*Val[v]);
        else Max(B[0].M[u][v+w*n-n],0ll);
    }

    for (int i=1;i<Log;i++) B[i]=B[i-1]*B[i-1];

    for (int i=1;i<=K;i++) scanf("%d%d%d",&Fl[i].time,&Fl[i].pos,&Fl[i].val);
    sort(&Fl[1],&Fl[K+1]);
    Fl[0].time=0;Fl[K+1].time=T;

    for (int i=1;i<=K+1;i++){
        int dru=Fl[i].time-Fl[i-1].time,lg=0;

        while (dru){
            if (dru&1) Mul(lg);
            ++lg;dru>>=1;
        }
        Ans.M[1][Fl[i].pos]+=Fl[i].val;
    }

    if (Ans.M[1][1]<=0) printf("-1\n");
    else printf("%lld\n",Ans.M[1][1]);

    return 0;
}

void Matrix::init(){
    for (int i=1;i<=SIZE;i++) for (int j=1;j<=SIZE;j++) M[i][j]=-INF;
    return;
}
void Matrix::outp(){
    for (int i=1;i<=SIZE;i++){
        for (int j=1;j<=SIZE;j++)
            if (M[i][j]<0) cout<<"-inf ";
            else cout<<M[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;return;
}

bool operator < (Festival A,Festival B){
    return A.time<B.time;
}

Matrix operator * (Matrix A,Matrix B){
    Bp.init();
    for (int i=1;i<=SIZE;i++)
        for (int j=1;j<=SIZE;j++)
            for (int k=1;k<=SIZE;k++)
                Max(Bp.M[i][j],A.M[i][k]+B.M[k][j]);
    return Bp;
}

void Mul(int opt){
    Bp.init();
    for (int j=1;j<=SIZE;j++)
        for (int k=1;k<=SIZE;k++)
            Max(Bp.M[1][j],Ans.M[1][k]+B[opt].M[k][j]);
    for (int i=1;i<=SIZE;i++) Ans.M[1][i]=Bp.M[1][i];
    return;
}