#include<iostream>
using namespace std;
int l[1000],r[1000];
int cnt;
void merge(int arr[],int n,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++)   l[i]=arr[left+i];
    for(int j=0;j<n2;j++)   r[j]=arr[mid+j];
    l[n1]=r[n2]=10000000;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(l[i]<=r[j]){
            arr[k]=l[i++];
        }else{
            arr[k]=r[j++];
        }
    }
}
void mergesort(int arr[],int n,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergesort(arr,n,left,mid);
        mergesort(arr,n,mid,right);
        merge(arr,n,left,mid,right);
    }
}

int main()
{
    int A[1000],n,i;
    cnt=0;
    cin>>n;
    for(i=0;i<n;i++) cin>>A[i];
    mergesort(A,n,0,n);
    for(i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}