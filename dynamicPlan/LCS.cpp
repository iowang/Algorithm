/**
 * 最长公共子序列
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[100][100];
int main()
{
    string arr,brr;
    cin>>arr>>brr;
    int m=arr.size();
    int n=brr.size();
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i]==brr[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                ans=ans>dp[i][j]?ans:dp[i][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                ans=ans>dp[i][j]?ans:dp[i][j];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}