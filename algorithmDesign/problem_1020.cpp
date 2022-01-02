#include<iostream>
#include<vector>
using namespace std;
struct rect{
	int x,y;
};
int main()
{
	int m;
	cin>>m;
	int n;
	int dp[501][501];
	vector<rect> vc;
	while(m--){
		vc.clear();
		cin>>n;
		rect re;
		for(int i=0;i<n;++i){
			cin>>re.x>>re.y;
			vc.push_back(re);
			
		}
		for(int i=0;i<n;++i) dp[i][i]=0;
		for(int r=1;r<=n-1;++r){
			for(int i=0;i<=n-r;++i){
				int j=i+r;
				dp[i][j]=dp[i+1][j]+vc[i].x*vc[i+1].x*vc[j].y;
				for(int k=i;k<=j;++k){
					int minn=dp[i][k]+dp[k+1][j]+vc[i].x*vc[k+1].x*vc[j].y;
					if(minn<dp[i][j])
						dp[i][j]=minn;
				}
			}
		}
		cout<<dp[0][n-1]<<endl;
	}
	return 0;
}
