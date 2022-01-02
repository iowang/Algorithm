#include<iostream>
using namespace std;
int main()
{
	int M;
	int N,K;
	cin>>M;
	while(M--){
		cin>>N>>K;
		int temp;
		long long int sum[21]={0};
		long long int dp[21][20]={0};
		for(int i=1;i<=N;++i){
			cin>>temp;
			sum[i]=sum[i-1]+temp;
		}
		for(int i=1;i<=N;++i) dp[i][0]=sum[i];
		for(int i=2;i<=N;++i){
			for(int j=1;j<=i-1 && j<=K;++j){
				for(int l=2;l<=N;++l){
					dp[i][j]=max(dp[i][j],dp[l-1][j-1]*(sum[i]-sum[l-1]));
				}
			}
		}
		cout<<dp[N][K]<<endl;
	}
	return 0;
}
