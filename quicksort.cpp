// 这是实现快速排序，快速排序是个不稳定排序，同时也是原地排序
#include<iostream>
using namespace std;
int arr[1000];
int partition(int start,int end){
    int x=arr[end];
    int i=start-1;
    int t;
    for(int j=0;j<end;j++){
        if(arr[j]<=x){
            i=i+1;
            t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
        }
    }
    arr[end]=arr[i+1];
    arr[i+1]=x;
    return i+1;
}
void quicksort(int left,int right){
    if(left<right){
        int q=partition(left,right);
        quicksort(left,q-1);
        quicksort(q+1,right);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    quicksort(0,n-1);
    for(int j=0;j<n;j++){
        if(j) cout<<" ";
        cout<<arr[j];
    }
    cout<<endl;
    return 0;
}