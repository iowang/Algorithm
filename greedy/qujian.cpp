/*
    给定一组区间，选出最多的区间使他们各不相交
    按照右端点的排序，
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct interval{
    int x;
    int y;
}q[100];

bool cmp(interval a,interval b){
    if(a.y==b.y){
        return a.x>b.x;
    }
    return a.y<b.y;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>q[i].x>>q[i].y;
    }
    sort(q,q+n,cmp);
    int ans=1,last=q[0].y;
    queue<interval> t;
    t.push(q[0]);
    for(int i=1;i<n;i++){
        if(q[i].x>=last){
            ans++;
            last=q[i].y;
            t.push(q[i]);
        }
    }
    cout<<ans<<endl;
    while(!t.empty()){
        interval temp=t.front();
        cout<<'('<<temp.x<<','<<temp.y<<')'<<" ";
        t.pop();
    }
    cout<<endl;
    return 0;
}