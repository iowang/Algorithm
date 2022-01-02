#include<iostream>
using namespace std;
double solve(int arr[],int brr[],int start1,int end1,int start2,int end2){
    int m1=(start1-end1)/2;
    int m2=(start2-end2)/2;
    if(arr[m1]==brr[m2]) return arr[m1];
    else if(arr[m1]<brr[m2]){
        return solve(arr,brr,m1,end1,start2,m2);
    }else{
        return solve(arr,brr,start1,m1,m2,end2);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int arr[1001];
        int brr[1001];
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i) cin>>arr[i];
        for(int j=0;j<m;++j) cin>>brr[j];
        double ans=solve(arr,brr,0,n,0,m);
        cout<<ans<<endl;
    }   
    return 0;
}