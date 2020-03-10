/*
    全排列：用递归的思想递归1～n
    首先递归1～n，接着是2～n.....
*/
#include<iostream>
using namespace std;
int used[1000]={0},pre[1000];
int num;
void permutation(int index){
    if(index==num+1){
        for(int i=1;i<=num;i++){
            cout<<pre[i];
        }
        cout<<endl;
    }

    for(int i=1;i<=num;i++){
        if(used[i]==0){
            used[i]=1;
            pre[index]=i;
            permutation(index+1);
            used[i]=0;
        }
    }
}
int main()
{
    cin>>num;
    permutation(1);
    return 0;
}