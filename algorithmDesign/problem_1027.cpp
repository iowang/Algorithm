#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Party{
	int st;
	int ed;
	int vl;
	int id;
}party[10001];
int frt[10001],dp[10001];
bool cmp(Party p1,Party p2){
	return p1.ed<p2.ed;
}
int main()
{
	int m;
	int n;
	cin>>m;
	while(m--){
		cin>>n;
		memset(frt,0,sizeof(frt));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i){
			cin>>party[i].st>>party[i].ed>>party[i].vl;
		}
		sort(party+1,party+n+1,cmp);
		for(int i=1;i<=n;++i) party[i].id=i;
		for(int i=n;i>=1;--i){
			for(int j=n-1;j>=1;--j){
				if(party[j].ed<=party[i].st){
					frt[i]=party[j].id;break;
				}
			}
		}
		
		for(int i=1;i<=n;++i){
			dp[i]=max(dp[i-1],dp[frt[i]]+party[i].vl);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
