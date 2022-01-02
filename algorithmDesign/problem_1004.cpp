#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int m;//表示有m行输入
	int n;//表示有n个数字
	vector<int> vc;//用来存储n个输入
	cin>>m;
	int ans;
	while(m--){
		vc.clear();
		cin>>n;
		int a;
		for(int i=0;i<n;++i){
			cin>>a;
			vc.push_back(a);
		}
		int len=vc.size();
		int mid=(len-1)/2;
		int mid1=mid/2;
		int mid2=(mid+len)/2;
		auto start=vc.begin();
		auto start_mid1=vc.begin()+mid1;
		auto start_mid=vc.begin()+mid;
		auto start_mid2=vc.begin()+mid2;
		auto end=vc.end();
//		cout<<*start_mid1<<"*"<<*start_mid<<"*"<<*start_mid2<<endl;
//		for(auto i=start;i<=start_mid1;++i) cout<<*i<<"(";cout<<endl;
		sort(start,start_mid1+1);
//		for(auto i=start;i<=start_mid1;++i) cout<<*i<<"(";cout<<endl;
		sort(start_mid1+1,start_mid+1);
		sort(start_mid+1,start_mid2+1);
		sort(start_mid2+1,end);
		for(auto i:vc) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
