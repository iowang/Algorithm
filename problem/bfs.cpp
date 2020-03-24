// 用bfs求联通快，其实实现跟bfs实现很类似的
#include<iostream>
#include<queue>
using namespace std;
const int maxn=100;
int m,n;//m行,n列
int ans;
int visit[maxn][maxn]={0};
int maxv[maxn][maxn];
struct node{
    /* data */
    int x,y;
}Node;

int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool judge(int x,int y){
// 判断x,y是否要访问
    if(x>=m||y>=n||x<0||y<0)  return false;
    if(visit[x][y]==1||maxv[x][y]==0) return false;
    return true;
}

void bfs(int x,int y){
    queue<node> q;
    Node.x=x;Node.y=y;
    q.push(Node);
    visit[x][y]=1;
    while(!q.empty()){
        node temp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int newx=temp.x+X[i];
            int newy=temp.y+Y[i];
            if(judge(newx,newy)){
                Node.x=newx;Node.y=newy;
                q.push(Node);
                visit[newx][newy]=1;
            }
        }
    }

}
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maxv[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(judge(i,j)){
                ans++;
                bfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}