#include<iostream>
using namespace std;
int main()
{
	int m;
	int n;
	cin>>m;
	while(m--){
		int arr[10001]={0};
		int dp[10001]={0};
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>arr[i];
			dp[i]=1;
		}
		int ans=0;
		for(int i=1;i<n;++i){
			for(int j=0;j<i;++j){
				if(arr[i]>=arr[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(dp[i],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
