#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        q.push(temp);
    }

    while(q.size()>1){
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        q.push(a+b);
    }

    cout<<q.top()<<endl;
    return 0;
}