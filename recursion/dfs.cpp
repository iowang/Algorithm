// 背包问题，给n个物品，重分别为W[i],价值为V[i],给一个背包V，该
// 如何选取物品使装的尽量多且价值最大
#include<iostream>
#include<algorithm>
using namespace std;
int maxvalue,w,n;
const int maxn=1000;
int W[maxn],V[maxn];
/*
void DFS(int index,int value,int weight){
    if(index==n){
        if(value>maxvalue&&weight<=w){
            maxvalue=value;
        }
        return ;
    }
    DFS(index+1,value,weight);//不选择第index件物品
    DFS(index+1,value+V[index],weight+W[index]);//选择第index件物品
}
*/
// 上面方法复杂度是指数级别的，因此需要进行剪枝

void DFS(int index,int value,int weight){
    if(index==n){
        if(value>maxvalue&&weight<=w){
            maxvalue=value;
        }
        return ;
    }
    DFS(index+1,value,weight);//不选择第index件物品
    if(weight+W[index]<=w){
        if(value+V[index]>maxvalue){
            maxvalue=value+V[index];
        }
        DFS(index+1,value+V[index],weight+W[index]);//选择第index件物品
    }
}

int main()
{
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>W[i];
    }
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    DFS(0,0,0);
    cout<<maxvalue<<endl;
    return 0;

}