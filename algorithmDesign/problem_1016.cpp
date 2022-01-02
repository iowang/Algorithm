#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int M,N,X;
	int vc[50001];
	cin>>M;
	bool flag=0;
	int rest=0;
	while(M--){
		
		cin>>N>>X;
		for(int i=0;i<N;++i) cin>>vc[i];
		sort(vc,vc+N);
//		cout<<vc[3];
//		for(auto j=0;j<N;++j) cout<<vc[j]<<"**";
		for(auto i=0;i<N;++i){
			rest=X-vc[i];
			flag=binary_search(vc,vc+N,rest);
			if(flag){
				cout<<"yes"<<endl;
				break;
			}
		}
		if(!flag) cout<<"no"<<endl;
	}
	return 0;
}
