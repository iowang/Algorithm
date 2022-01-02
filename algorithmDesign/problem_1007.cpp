#include<iostream>
#include<cstring>
using namespace std;
int c[41]={0};

int makeConut(int x, int y)   
{
	int ans = 0;
	while(x <= y) ans = ans * 10 + c[x++];
	return ans;
}
void trans(string s,int n,int brr[][41]){
	for(int i=1;i<=n;i++) c[i]=(s[i-1]-'0');
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			brr[i][j] = makeConut(i, j);
}

void reset1(int arr[][7]){
	for(int i=0;i<41;i++)
		for(int j=0;j<7;j++)
			arr[i][j]=0;
}
void reset2(int arr[][41]){
	for(int i=0;i<41;i++)
		for(int j=0;j<41;j++)
			arr[i][j]=0;
}
void solve(int n,int m,int dp[][7],int arr[][41]){
	for(int i=1;i<=n;i++) dp[i][0]=arr[1][i];
	for(int k=1;k<=m;k++)
		for(int j=k+1;j<=n;j++)
			for(int i=j-1;i>=k;i--)
				dp[j][k]=max(dp[j][k],dp[i][k-1]*arr[i+1][j]);
	cout<<dp[n][m]<<endl;
}
int main()
{
	int m;
	int n,k;
	string s;
	int dp[41][7];
	int arr[41][41];
	cin>>m;
	while(m--){
		cin>>n>>k;
		cin.ignore();
		cin>>s;
		reset1(dp);
		reset2(arr);
		trans(s,n,arr);
		solve(n,k,dp,arr);
	}
}
