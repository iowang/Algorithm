/**
 * 数塔问题，第一层一个数字，第二次两个数字........第ｎ层ｎ个数字
 * 每次只能走下两个数字的其中一个，寻找一条路径使得数字之和最大
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;
int arr[maxn][maxn];
int dp[maxn][maxn];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    // dp找数字之和最大
    for(int i=0;i<n;i++){
        dp[n-1][i]=arr[n-1][i];
    }
    // 从下往上走，如果从下面第一个走大于从另一个走就从这个走
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+arr[i][j];
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}