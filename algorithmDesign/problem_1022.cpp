#include<iostream>
using namespace std;
int main()
{
	int m;
	cin>>m;
	string str1;
	string str2;
	while(m--){
		cin>>str1;
		cin>>str2;
		int dp[501][501]={{0}};
		int len1=str1.size();
		int len2=str2.size();
		for(int i=0;i<len1;++i) dp[i][0]=0;
		for(int j=0;j<len2;++j) dp[0][j]=0;
		for(int i=1;i<=len1;++i){
			for(int j=1;j<=len2;++j){
				if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
	return 0;
}
