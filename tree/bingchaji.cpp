/**
 * 并查集的问题
 * 如果A和B是好朋友那么B和A也是好朋友
 * 如果A和C是好朋友B和C是好朋友那么A和B也是好朋友
 * 输入n个人，m组朋友，判断有几组好朋友
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;
int Father[maxn];
int IsRoot[maxn];
int n,m;
void init(){
    for(int i=1;i<=n;i++){
        Father[i]=i;
        IsRoot[i]=false;
    }
}
int FindFather(int x){
    if(x==Father[x]){
        return x;
    }else{
        int par=FindFather(Father[x]);
        Father[x]=par;
        return par;
    }
}
void Union(int a,int b){
    int fa=FindFather(a);
    int fb=FindFather(b);
    if(fa!=fb){
        Father[fa]=fb;
    }
}
int main()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    for(int i=1;i<=n;i++){
        IsRoot[FindFather(i)]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(IsRoot[i]==true)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}