// 给一组数，求出组合最小值
#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=9;i++){
        if(arr[i]!=0){
            cout<<i;
            arr[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++){
        while(arr[i]!=0){
            cout<<i;
            arr[i]--;
        }
    }
    cout<<endl;
    return 0;
}