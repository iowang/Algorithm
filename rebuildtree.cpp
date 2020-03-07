/*
    给出二叉树的先序遍历和中序遍历输出后序遍历的节点编号
    顺便实现一下层次遍历的节点编号
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n,pos;
vector<int> pre,in,last;
// 这个地方直接就是后序遍历了，先建左子树，在建右子树，最后把根放进去
void create(int l,int r){
    if(l>=r) return;
    int root=pre[pos++];
    int m=distance(in.begin(),find(in.begin(),in.end(),root));
    create(l,m);
    create(m+1,r);
    last.push_back(root);
}
void solve(){
    pos=0;
    create(0,pre.size());
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<last[i];
    }
    cout<<endl;
}
int main()
{
    int k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        pre.push_back(k);
    }
    for(int j=0;j<n;j++){
        cin>>k;
        in.push_back(k);
    }
    solve();
    return 0;
}