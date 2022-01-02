#include<iostream>
using namespace std;
int main()
{
	int m;
	cin>>m;
	int arr[101];
	int dp[100];
	int ans;
	int n;
	while(m--){
		cin>>n;
		ans=0;
		for(int l=0;l<n;++l){
			cin>>arr[l];
			dp[l]=1;	
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(arr[j]>=arr[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
		}
		
		int brr[101]={0};
		int j=0;
		brr[0]=arr[0];
		for(int i=0;i<n;++i){
			if(arr[i]<brr[0]) brr[0]=arr[i];
			else if(arr[i]>brr[j]){
				++j;brr[j]=arr[i];
			}
			else if(arr[i]>brr[0]&&arr[i]<brr[j]){
				for(int k=0;k<=j;k++){
					if(arr[i]<brr[k]){
						brr[k]=arr[i];
						break;
					}
				}
			}
		}
		cout<<ans<<" "<<j+1<<endl;
	}
	return 0;
} 
