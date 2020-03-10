// 本题是计算最优解，利用的是二分查找+贪心算法
#include<iostream>
using namespace std;
int n,k;
int T[100];
bool check(int p){
    int i=0;
    for(int j=0;j<k;j++){
        int s=0;
        while(s+T[i]<=p){
            s+=T[i];
            i++;
            if(i==n) return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>T[i];
    }
    int mid;
    int left=0,right=1000000;
    while(right-left>1){
        mid=(left+right)/2;
        if(check(mid)){
            right=mid;
        }else{
            left=mid;
        }
    }
    cout<<mid<<endl;
    return 0;
}