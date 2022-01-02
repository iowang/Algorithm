#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int m;
	int n;
	int misle[100];
	int dp[100];
	int ans;
	cin>>m;
	while(m--){
		ans=-1;
		cin>>n;
		for(int l=0;l<n;++l){
			cin>>misle[l];
			dp[l]=1;	
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(misle[j]>misle[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
