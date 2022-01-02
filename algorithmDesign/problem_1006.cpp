#include<iostream>
#include<cstring>
using namespace std;
//������С��

void adjust_heap(int arr[],int p,int n){
	int left=2*p+1;
	int right=2*p+2;
	int min_node=p;
	if(left<n&&arr[left]<arr[min_node]) min_node=left;
	if(right<n&&arr[right]<arr[min_node]) min_node=right;
	if(min_node!=p){
		swap(arr[min_node],arr[p]);
		adjust_heap(arr,min_node,n);
	}
}

void make_minheap(int arr[],int n){
	for(int i=n/2;i>=0;--i){
		adjust_heap(arr,i,n);
	}
}

 
int main()
{
	int m;//��ʾ��m������
	int n;//��ʾ��n������
	int arr[1005];//�����洢n������
	cin>>m;
	int ans;
	while(m--){
		memset(arr,0,sizeof(arr));
		cin>>n;
		for(int i=0;i<n;++i) cin>>arr[i];
		make_minheap(arr,n);
		for(int j=0;j<n-1;j++) cout<<arr[j]<<" ";
		cout<<arr[n-1]<<endl;
	}
	return 0;
}
