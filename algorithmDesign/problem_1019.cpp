#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
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
		for(int i=0;i<=C;++i) dp[0][i]=0;
		for(int i=1;i<=N;++i){
			for(int j=0;j<=C;++j){
				if(size[i]>j) dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j],dp[i-1][j-size[i]]+value[i]);
			}
		}
		cout<<dp[N][C]<<endl;
	}
	return 0;
}
