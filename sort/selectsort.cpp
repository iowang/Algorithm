#include<iostream>
using namespace std;
void selectsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[minj]){
                minj=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minj];
        arr[minj]=temp;

        for(int l=0;l<n;l++){
            cout<<arr[l]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    int arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectsort(arr,n);
    
    return 0;
}