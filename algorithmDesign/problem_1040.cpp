#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,target;
        cin>>n>>m>>target;
        vector<int> vc[1001];
        int k;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>k;
                vc[i].push_back(k);
            }
        }
        int x=m-1,y=0;
		bool flag=0;
		while(x>=0 && y<n){
			if(vc[x][y]==target){
				flag=1;
				break;
			}
			else if(vc[x][y]>target)x--;
			else y++;//a[x][c]<target
		}
		cout<<(flag?"true":"false")<<endl;
    }
    system("pause");
    return 0;
}