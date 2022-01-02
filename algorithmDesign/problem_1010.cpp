#include<iostream>
#include<cstring>
using namespace std;
int father;
int arr[20001];
int save_mid[15];
int binary_search(int low,int high,int x){
	int mid;
	int i=0;
	while(low<=high){
		mid=(low+high)/2;
		save_mid[i++]=mid;
//		cout<<i<<"*"<<endl;
		if(arr[mid]==x){
			father=arr[save_mid[i-2]];
			return mid+1;	
		}else if(arr[mid]<x){
			low=mid+1;
		}else{
			high=mid-1;
		}
		
	}
	if(low>high){
		father=arr[mid];
//		cout<<mid<<"*";
		return 0;	
	}
	return 0;
}
int main()
{
	int m;
	int n,x;
	cin>>m;
	int ans;
	while(m--){
		cin>>n>>x;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;++i) cin>>arr[i];
		ans=binary_search(0,n-1,x);
		if(ans){
//			cout<<ans<<endl;
			cout<<"success, father is "<<father<<endl;
		}else{
//			cout<<ans<<endl;
			cout<<"not found, father is "<<father<<endl;
		}
//		for(int i=0;i<15;i++) cout<<save_mid[i]<<" ";
//		cout<<endl;
	}
	return 0;
}
