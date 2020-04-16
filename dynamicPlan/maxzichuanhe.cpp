/**
 * 最大连续子串和O(n)复杂度做法
 * dp存储以Ａ[i]结尾的最大子串和
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int arr[100];
    int dp[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=-9999;
    }

    int ans=-9999;
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>dp[i-1]+arr[i]){
            dp[i]=arr[i];
            ans=ans>dp[i]?ans:dp[i];
        }else{
            dp[i]=dp[i-1]+arr[i];
            ans=ans>dp[i]?ans:dp[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}