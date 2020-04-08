#include<iostream>
using namespace std;
const int inf=0xffffff;
const int maxn=1000;
bool vis[maxn];
int n,m,s;
int g[maxn][maxn];
int dis[maxn];
void dijkstra(int s){
    fill(dis,dis+maxn,inf);
    dis[s]=0;
    for(int i=0;i<n;i++){
        int d=inf;
        int u=-1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<d){
                u=j;d=dis[j];
            }
        }
        if(u==-1) return;
        vis[u]=1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&g[u][j]!=inf&&dis[j]>g[u][j]+dis[u]){
                dis[j]=g[u][j]+dis[u];
            }
        }
    }
}
int main()
{
    int u,v,w;
    cin>>n>>m>>s;
    fill(g[0],g[0]+maxn*maxn,inf);
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        g[u][v]=w;
    }
    dijkstra(0);
    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    return 0;
}