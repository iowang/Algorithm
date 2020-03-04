#include<iostream>
using namespace std;
void insert_sort(int arr[],int n);
int main()
{
    int n;
    int arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insert_sort(arr,n);
    return 0;
}

void insert_sort(int arr[],int n){
    int temp,j;
    for(int i=0;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}