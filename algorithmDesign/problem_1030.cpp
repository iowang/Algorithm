#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    int n;
    cin>>t;
    vector<int> arr;
    vector<int> flag;
    while (t--)
    {
        cin>>n;
        arr.clear();
        flag.clear();
        int x;
        for(int i=0;i<2*n;++i){
            cin>>x;
            arr.push_back(x);
            flag.push_back(0);
        }
        int ans=0;
        for(int i=0;i<2*n;++i){
            if(!flag[i]){
                for(int j=i+1;j<2*n;++j){
                    if(!flag[j]&&arr[j]!=arr[i]){
                        ans+=(j-i);
                        flag[i]=1;
                        flag[j]=1;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}