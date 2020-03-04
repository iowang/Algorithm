#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n){
    int flag=1;
    int temp;
    while(flag){
        flag=0;
        for(int j=n-1;j>0;--j){
            if(arr[j]<arr[j-1]){
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}