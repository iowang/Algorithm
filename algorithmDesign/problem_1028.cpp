#include<iostream>
using namespace std;
const int INF=1e7;
int map[501][501];
int dist[501];
int flag[501];
int dijkstra(int s,int u,int n){
	for(int i=1;i<=n;++i){
		flag[i]=0;
		dist[i]=map[s][i];
		map[i][i]=0;
	}
	flag[s]=1;dist[s]=0;
	for(int i=1;i<=n;++i){
		int temp=INF,t=s;
		for(int j=1;j<=n;++j){
			if(!flag[j]&&temp>dist[j]){
				temp=dist[j];t=j;
			}
		}
		if(t==s) break;
		flag[t]=1;
		for(int j=1;j<=n;++j){
			if(!flag[j]&&map[t][j]<INF){
				if(dist[j]>(dist[t]+map[t][j]))
					dist[j]=dist[t]+map[t][j];
			}
		}
	}
	return dist[u]==1e7?-1:dist[u];
}
int main()
{
	int m,n,e,s,t;
	cin>>m;
	while(m--){
		cin>>n>>e>>s>>t;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)
				map[i][j]=INF;
		}
		int a,b,c;
		for(int i=0;i<e;++i){
			cin>>a>>b>>c;
			map[a][b]=min(map[a][b],c);
		}
		int ans=dijkstra(s,t,n);
		cout<<ans<<endl;
	}
	return 0;
}
