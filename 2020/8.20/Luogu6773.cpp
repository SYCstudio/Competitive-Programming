#include<bits/stdc++.h>
using namespace std;

const int Mod=998244353;
const int maxN=500050;

class SegmentData{
    public:
    int key,ls,rs,l,r,mul;
    SegmentData(){
        mul=1;
    }
    int size(){
        return r-l+1;
    }
    int mid(){
        return (l+r)>>1;
    }
};

int n,m,Depth[maxN],Anc[maxN];
vector<int> T[maxN];
int usum,vsum,vall;
int rt[maxN],scnt;
SegmentData S[maxN*20];

void dfs_init(int u,int fa);
void dfs_calc(int u,int fa);
int Newnode(int l,int r);
void Mul(int x,int key);
void Push(int x);
void Insert(int &x,int l,int r,int pos);
int Query(int x,int l,int r);
int Merge(int x,int y);
void outps(int x,int l,int r);

int main(){
    freopen("destiny.in","r",stdin);
    freopen("destiny.out","w",stdout);

    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        T[u].push_back(v);T[v].push_back(u);
    }

    dfs_init(1,0);

    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        if (Depth[u]>Depth[v]) swap(u,v);
        if (Depth[Anc[v]]<Depth[u]) Anc[v]=u;
    }

    //for (int i=1;i<=n;i++) cout<<Anc[i]<<" ";cout<<endl;
    //for (int i=1;i<=n;i++) cout<<Depth[i]<<" ";cout<<endl;

    dfs_calc(1,0);
    printf("%d\n",Query(1,0,0));

    return 0;
}

void dfs_init(int u,int fa){
    Depth[u]=Depth[fa]+1;
    for (int i=0;i<T[u].size();i++)
        if (T[u][i]!=fa) dfs_init(T[u][i],u);
    return;
}

void dfs_calc(int u,int fa){
    Insert(rt[u],0,n,Depth[Anc[u]]);
    for (int i=0;i<T[u].size();i++){
        int v=T[u][i];
        if (v==fa) continue;
        dfs_calc(v,u);
        usum=vsum=0;vall=Query(rt[v],0,Depth[u]);
        rt[u]=Merge(rt[u],rt[v]);

        //cout<<u<<" "<<v<<":";
        //outps(rt[u],0,n);cout<<endl;
    }
    //cout<<"finish "<<u<<":";
    //outps(rt[u],0,n);cout<<endl;
    return;
}

int Newnode(int l,int r){
    int id=++scnt;
    S[id].l=l;S[id].r=r;S[id].mul=1;
    return id;
}

void Mul(int x,int key){
    S[x].key=(1ll*key*S[x].key)%Mod;
    S[x].mul=(1ll*key*S[x].mul)%Mod;
    return;
}

void Push(int x){
    if (S[x].size()==1) return;
    if (S[x].mul==1) return;
    //if (S[x].ls==0) S[x].ls=Newnode(S[x].l,S[x].mid());
    //if (S[x].rs==0) S[x].rs=Newnode(S[x].mid()+1,S[x].r);
    if (S[x].ls) Mul(S[x].ls,S[x].mul);
    if (S[x].rs) Mul(S[x].rs,S[x].mul);
    S[x].mul=1;return;
}

void Insert(int &x,int l,int r,int pos){
    x=Newnode(l,r);S[x].key=1;
    if (l==r) return;
    if (S[x].mid()>=pos) Insert(S[x].ls,l,S[x].mid(),pos);
    else Insert(S[x].rs,S[x].mid()+1,r,pos);
    return;
}

int Query(int x,int l,int r){
    if (x==0) return 0;
    if ((l==S[x].l)&&(r==S[x].r)) return S[x].key;
    Push(x);
    if (r<=S[x].mid()) return Query(S[x].ls,l,r);
    else if (l>=S[x].mid()+1) return Query(S[x].rs,l,r);
    else return (Query(S[x].ls,l,S[x].mid())+Query(S[x].rs,S[x].mid()+1,r))%Mod;
}

int Merge(int x,int y){
    if ((x==0)&&(y==0)) return 0;
    if ((x!=0)&&(y==0)){
        usum=(usum+S[x].key)%Mod;
        Mul(x,(vsum+vall)%Mod);
        return x;
    }
    if ((x==0)&&(y!=0)){
        vsum=(vsum+S[y].key)%Mod;
        Mul(y,usum);
        return y;
    }
    if (S[x].l==S[x].r){
        vsum=(vsum+S[y].key)%Mod;
        int tmp=1ll*(vall+vsum)%Mod*S[x].key%Mod;
        tmp=(tmp+1ll*S[y].key*usum%Mod)%Mod;
        usum=(usum+S[x].key)%Mod;
        S[x].key=tmp;return x;
    }
    Push(x);Push(y);
    S[x].ls=Merge(S[x].ls,S[y].ls);
    S[x].rs=Merge(S[x].rs,S[y].rs);
    S[x].key=(S[S[x].ls].key+S[S[x].rs].key)%Mod;
    return x;
}

void outps(int x,int l,int r){
    if (x==0) return;
    if (l==r){
        cout<<l<<"["<<S[x].key<<"] ";return;
    }
    Push(x);
    outps(S[x].ls,l,S[x].mid());
    outps(S[x].rs,S[x].mid()+1,S[x].r);
    return;
}