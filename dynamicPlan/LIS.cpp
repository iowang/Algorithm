/**
 * 最长不降子序列，采用动态规划算法
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[100];
    int dp[100][100];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i][i]=1;
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[j]>=arr[i]){
                dp[i][j]=dp[i][j-1]+1;
                ans=ans>dp[i][j]?ans:dp[i][j];
            }else{
                dp[i][j]=dp[i][j-1];
                ans=ans>dp[i][j]?ans:dp[i][j];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}