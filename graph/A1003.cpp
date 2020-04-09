/**
 * 给出N个城市，M条无向边，每个城市都有一定数目的救援小组，所有边边权已知
 * 现在给出起点和终点，求出从起点到终点的最短路径数目条数，以及最短路径上救援小组数目之和
 * 如果有多个最短路径，输出数目之和最大的那个
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,st,ed;
const int maxn=1000;
const int inf=0xfffff;
int g[maxn][maxn];
int d[maxn],vis[maxn];
int w[maxn],weight[maxn];//这是用来医疗队的
int nums[maxn];//这是用来定义有几个最短路径的
void dijkstra(int s){
    fill(d,d+maxn,inf);
    fill(w,w+maxn,0);
    fill(nums,nums+maxn,0);
    w[s]=weight[s];
    nums[s]=1;//最短路一定有一条
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,dis=inf;
        for(int j=0;j<n;j++){
            if(!vis[j]&&d[j]<dis){
                u=j;dis=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&g[u][j]!=inf){
                if(g[u][j]+d[u]<d[j]){
                    d[j]=g[u][j]+d[u];
                    w[j]=w[u]+weight[j];//如果是最短路径，那么我就把这条路上的医疗队数量加起来
                    nums[j]=nums[u];//最短路径数暂时不更新
                }else if(g[u][j]+d[u]==d[j]){
                    //有大于一条的最短路了
                    nums[j]=nums[u]+1;
                    //判断从u过来的医疗队总数是否大于已经来到的医疗队总数
                    if(w[j]<w[u]+weight[j]){
                        w[j]=w[u]+weight[j];
                    }
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m>>st>>ed;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    int a,b,c;
    fill(g[0],g[0]+maxn*maxn,inf);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=c;
    }
    dijkstra(st);
    cout<<nums[ed]<<" "<<w[ed]<<endl;
    return 0;
}