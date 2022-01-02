#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int a,b,h;
	int arr[100000]={0};
	int maxx=-1;
	int minn=99999;
	while(N--){
		cin>>a>>b>>h;
		for(int i=a;i<b;++i){
			maxx=max(maxx,b);
			minn=min(minn,a);
			arr[i]=max(arr[i],h);
		}
	}
	for(int i=minn;i<=maxx;++i){
		if(arr[i]!=arr[i-1]){
			cout<<i<<" "<<arr[i]<<endl;
		}
	}
	return 0;
}
