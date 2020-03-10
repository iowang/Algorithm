#include<iostream>
using namespace std;
bool binary_search(int arr[],int k,int n)
{
    int left=0,right=n;
    while(left<right){
        int mid=(left+right)/2;
        if(arr[mid]==k){
            return 1;
        }else if(arr[mid]<k){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return 0;
}
int main()
{
    int n,q;
    int arr[100],brr[100];
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<q;j++){
        cin>>brr[j];
    }
    int ans=0;
    for(int k=0;k<q;k++){
        if(binary_search(arr,brr[k],n)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}