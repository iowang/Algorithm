// 对数组进行分割，是的左面全部小于等于这个值，右面都大于这个值
#include<iostream>
using namespace  std;
int arr[1000];
// 函数里面相当于两个指针一个不断找比这个值小的，另一个在那地方等待交换
int partition(int p,int r){
    int x=arr[r];
    int i=p-1;
    int t;
    for(int j=p;j<r;j++){
        if(arr[j]<=x){
            i=i+1;
            t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
        }
    }
    t=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=t;
    return i+1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int q=partition(0,n-1);
    for(int i=0;i<n;i++){
        if(i) cout<<" ";
        if(i==q){
            cout<<'['<<arr[i]<<']';
        }else{
        cout<<arr[i];
        }
    }
    cout<<endl;
    return 0;
}