#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int di;
    int pi;
};
const int N=5e4+1;
bool cmp(node a,node b){
    if(a.di==b.di){
        return a.pi>b.pi;
    }else{
        return a.di<b.di;
    }
}
node task[N];
struct tmp{
    bool operator()(const int x,const int y){return task[x].pi>task[y].pi;}
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long ans=0;
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>task[i].di>>task[i].pi;
        }
        sort(task,task+n,cmp);
        priority_queue<int,vector<int>,tmp>q;
        for(int i=0;i<n;++i){
            if(q.size()<task[i].di) q.push(i);
            else if(task[q.top()].pi<task[i].pi){
                q.pop();
                q.push(i);
            }
        }
        while(!q.empty()){
            ans+=task[q.top()].pi;
            q.pop();
        }


        cout<<ans<<endl;
    }
    
    return 0;
}