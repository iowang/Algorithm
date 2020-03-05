/*
    折半插入排序的实现：使用这半查找和插入排序整合而成
*/
#include<iostream>
using namespace std;
void half_insert_sort(int arr[],int n){
    int temp,low,high;
    for(int i=1;i<=n;i++){
        temp=arr[i];
        low=1;high=i-1;//默认之前的都排好序了，直接在这里面来插入
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>temp){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        for(int j=i-1;j>=high+1;++j){
            arr[j+1]=arr[j];
        }
        arr[high+1]=temp;
    }
}
int main()
{
    int arr[100],n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    half_insert_sort(arr,n);
    for(int i=1;i<=n;i++){
        if(i-1){
            cout<<" ";
        }
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}