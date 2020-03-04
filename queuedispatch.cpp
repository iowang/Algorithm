#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct node{
    string name;
    int time;
    node(string name,int time):name(name),time(time){}
};
int main()
{
    queue<node> q;
    int n,p;
    cin>>n>>p;
    string name;
    int time;
    for(int i=0;i<n;i++){
        cin>>name>>time;
        q.push(node(name,time));
    }
    int protime=0;
    int left=p;
    while(!q.empty()){
        node n=q.front();
        q.pop();
        if(left<=n.time){
            protime+=left;
            n.time-=left;
            if(n.time==0){
                cout<<n.name<<" "<<protime<<endl;
            }else{
                q.push(n);
            }
            left=p;
        }else{
            protime+=n.time;
            cout<<n.name<<" "<<protime<<endl;
            left=p-n.time;
        }
    }
    return 0;
}