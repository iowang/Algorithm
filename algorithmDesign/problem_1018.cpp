#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	const int minn=-99999;
	int M;
	int N,C;
	int size[501];
	int value[501];
	int dp[501][501];
	cin>>M;
	while(M--){
		cin>>N>>C;
		for(int i=1;i<=N;++i){
			cin>>size[i]>>value[i];
		}
		for(int i=0;i<=N;++i){
			for(int j=0;j<=C;++j)
				dp[i][j]=minn;
		}
		for(int i=0;i<=N;++i) dp[i][0]=0;
		for(int i=1;i<=N;++i){
			for(int j=0;j<=C;++j){
				if(size[i]>j) dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j],dp[i-1][j-size[i]]+value[i]);
			}
		}
		if(dp[N][C]<0) cout<<0<<endl;
		else cout<<dp[N][C]<<endl;
	}
	return 0;
}
