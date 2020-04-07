#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int id;
    int layer;
    node(int id):id(id){}
    node(int id,int layer):id(id),layer(layer){}
};

int n,l;
vector<node> v[100];
bool flag[100]={0};

int solve(int m){
    
    int ans=0;
    queue<node> q;
    q.push(node(m,0));
    while(!q.empty()){
        node t=q.front();
        q.pop();
        flag[t.id]=1;
        for(int i=0;i<v[t.id].size();i++){
            node nxt=v[t.id][i];
            nxt.layer=t.layer+1;
            if(!flag[nxt.id]&&nxt.layer<=l){
                ans++;
                q.push(nxt);
                flag[nxt.id]=1;
            }
        }
    }
    return ans;
}
int main()
{
    cin>>n>>l;
    // 建立关系网
    for(int i=1;i<=n;i++){
        int total;
        cin>>total;
        int a;
        while(total--){
            cin>>a;
            v[a].push_back(node(i));
        }
    }
    int query;
    cin>>query;
    int m;
    int ans;
    while(query--){
        for(int i=0;i<100;i++) flag[i]=0;
        cin>>m;
        ans=solve(m);
        cout<<ans<<endl;
    }
    return 0;
}