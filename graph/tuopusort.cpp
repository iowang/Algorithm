/**
 * 拓扑排序先找到入度为０的点删除度和边加入队列
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1000;
vector<int> g[maxn];
int n,m,indegree[maxn];
bool topologicalsort(){
    int num=0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
        num++;
    }
    if(num==n)  return true;
    else return false;
}
int main()
{

}