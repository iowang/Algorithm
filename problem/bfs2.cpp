// n*m的迷宫，*代表墙壁，"."表示平地，S表示平地，T代表终点，每次只能上下左右移动
// 并且给出起点和终点坐标，求出最小步数
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Node{
    int x,y;
    int step;
}S,T,node;//起点，终点
const int maxn=100;
int m,n;
char maze[maxn][maxn];
int vis[maxn][maxn]={0};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int test(int x,int y){
    if(x>=m||x<0||y>=n||y<0) return false;
    if(vis[x][y]==1||maze[x][y]=='*') return false;
    return true;
}
void bfs(){
    queue<Node> q;
    q.push(S);
    while(!q.empty()){
        Node top=q.front();
        q.pop();
        if(top.x==T.x&&top.y==T.y){
            cout<<top.step<<endl;
            return ;
        }
        for(int i=0;i<4;i++){
            int newx=top.x+X[i];
            int newy=top.y+Y[i];
            if(test(newx,newy)){
                node.x=newx;node.y=newy;
                node.step=top.step+1;
                q.push(node);
                vis[newx][newy]=1;
            }
        }
    }
}
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }

    cin>>S.x>>S.y>>T.x>>T.y;
    S.step=T.step=0;
    bfs();
    // cout<<T.step<<endl;
    return 0;
}