#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> ans;
bool tupuSort(vector<vector<int>> &g,int n,vector<int> &indegree){
    ans.clear();
    int num=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        ans.push_back(u);
        q.pop();
        for(int i=0;i<g[u].size();++i){
            int v=g[u][i];
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
        g[u].clear();
        num++;
    }
    if(num==n) return true;
    else return false;
}

int main()
{
    int t;
    int n,m;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        vector<vector<int>> graph(n+1);
        vector<int> degree(n+1);
        for(int i=0;i<m;++i){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            degree[y]++;
        }
        bool result=tupuSort(graph,n,degree);
        if(result){
            for(int i=0;i<n-1;++i){
                cout<<ans[i]<<" ";
            }
            cout<<ans[n-1]<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    system("pause");
    return 0;
}