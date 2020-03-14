/*
    快速幂模板,求a^b%m;
*/
#include<iostream>
using namespace std;
typedef long long ll;
ll quickmul(ll a,ll b,ll m){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=ans*a%m;
        }
        a=a*a%m;
        b>>=1;
    }
    return ans;
}

int main()
{
    int a=2,b=4,mod=5;//即求2^4%5=1
    cout<<quickmul(a,b,mod)<<endl;
    return 0;
}