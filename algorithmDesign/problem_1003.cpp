#include<iostream>
#include<cstring>
using namespace std;

void bubble_sort(int arr[],int n){
	int temp;
	int i=0;
//	for(int i=0;i<n-1;i++){
	for(int j=0;j<n-i-1;j++){
		if(arr[j+1]<arr[j]){
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
	for(int k=0;k<n;++k) cout<<arr[k]<<" ";
	cout<<endl;
//	}
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
		bubble_sort(arr,n);
//		for(int i=0;i<n;++i){
//			cout<<arr[i]<<" ";
//		}
//		cout<<endl;
	}
	return 0;
}
