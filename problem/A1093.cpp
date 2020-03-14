/*
    给一个字符串有PAT三个字母组成，求这个字符串包含了多少PAT这个子序列的
    解法思路: 1 直接暴力法，但是时间复杂度太大
             2 可以看A前面有多少个P，后面有多少个T，求p可以用前缀和，计算T就直接计算了  
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10000,mod=1000000007;
int leftp[maxn],rightt;
int main()
{
    string s;
    cin>>s;
    int len=s.length();
    // 统计P
    for(int i=0;i<len;i++){
        if(i>0){
            leftp[i]=leftp[i-1];
        }
        if(s[i]=='P'){
            leftp[i]++;
        }
    }
    int ans=0;
    for(int j=len-1;j>=0;j--){
        if(s[j]=='T'){
            rightt++;
        }
        if(s[j]=='A'){
            ans+=(leftp[j]*rightt)%mod;
        }
    }
    cout<<ans<<endl;
    return 0;

}