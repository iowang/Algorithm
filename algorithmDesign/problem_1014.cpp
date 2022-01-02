#include<iostream>
using namespace std;
int dp[50001];
int main()
{
	int m;
	int n;
	int arr[50001];
	cin>>m;
	while(m--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
		dp[0]=arr[0];
		for(int i=1;i<n;i++){
			dp[i]=max(arr[i],arr[i]+dp[i-1]);
		}
		int ans=dp[0];
		for(int i=1;i<n;++i){
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
