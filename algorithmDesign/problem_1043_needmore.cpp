#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n,m;
    while (t--)
    {
        cin>>n>>m;
        int ans=0;
        while (m)
        {
            m/=2;
            ans++;
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}