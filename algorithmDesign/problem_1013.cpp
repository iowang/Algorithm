#include<iostream>
#include<cstring>
using namespace std;

int merge(int arr[],int low,int mid,int high){
	int brr[50005];
	int count=0;
	int i=low,j=mid+1,k=0;
	for(k=low;k<=high;++k){
		if(i==mid+1){
			brr[k]=arr[j++];
		}else if(j==high+1){
			brr[k]=arr[i++];
		}else if(arr[i]<=arr[j]){
			brr[k]=arr[i++];
		}else{
			count+=(mid-i+1);
			brr[k]=arr[j++];
		}
	}
	for(int t=low;t<=high;++t) arr[t]=brr[t];
	return count;
}

int merge_sort(int arr[],int low,int high){
	int leftans,rightans,curans;
	if(low>=high) return 0;
	int mid=(low+high)/2;
	leftans=merge_sort(arr,low,mid);
	rightans=merge_sort(arr,mid+1,high);
	if(arr[mid]<=arr[mid+1]) return leftans+rightans;
	curans=merge(arr,low,mid,high);
	return leftans+rightans+curans;
	
}

int main()
{
	int M,N;
	cin>>M;
	int ans;
	int arr[50003];
	while(M--){
		cin>>N;
		for(int i=0;i<N;++i) cin>>arr[i];
		ans=merge_sort(arr,0,N-1);
		cout<<ans<<endl;
	}
	return 0;
}
