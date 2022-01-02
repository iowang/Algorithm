#include<iostream>
using namespace std;
int main()
{
	int m;
	int n,k;
	cin>>m;
	while(m--){
		int dp[10001]={0};
		int length[10000];
		int value[10000];
		cin>>n>>k;
		for(int i=0;i<k;++i){
			cin>>length[i]>>value[i];
		}
		int temp;
		for(int i=1;i<=n;++i){//正着写可以让物品被无限取，满足完全背包，而0-1背包是要倒着写背包容量，满足物品只取一次 
			for(int j=0;j<k;++j){
				if(i>=length[j]){
					temp=dp[i-length[j]]+value[j];
					if(dp[i]<=temp) dp[i]=temp;
				}else{
//					dp[i]=dp[i-1];
				}
			}
		}
		
		cout<<dp[n]<<endl;
	}
	return 0;
}
