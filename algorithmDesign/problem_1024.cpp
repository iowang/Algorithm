#include<iostream>
#include<cmath>
#include<cstdio>
double p[501];
double q[501];
double dp[501][501];
double cost[501][501];
double nums[501];
using namespace std;
int main()
{
	int m;
	int n;
	cin>>m;
	while(m--){
		cin>>n;
		for(int i=0;i<n;++i) cin>>nums[i];
		for(int i=1;i<=n;++i) cin>>p[i];
		for(int i=0;i<=n;++i) cin>>q[i];
		for(int i=1;i<=n;++i){
			dp[i][i-1]=0.0;
			cost[i][i-1]=q[i-1];
		}
		for(int t=1;t<=n;++t){
			for(int i=1;i<=n;++i){
				int j=i+t-1;
				cost[i][j]=cost[i][j-1]+p[j]+q[j];
				dp[i][j]=dp[i][i-1]+dp[i+1][j];
				
				for(int k=i+1;k<=j;++k){
					double temp=dp[i][k-1]+dp[k+1][j];
					if(temp<dp[i][j] && fabs(temp-dp[i][j])>1e-6) dp[i][j]=temp;
					
				}
				dp[i][j]+=cost[i][j];
			}
		}
		printf("%.6f\n",dp[1][n]);
	}
	return 0;
}
