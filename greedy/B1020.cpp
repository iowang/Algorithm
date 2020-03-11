// PAT Ｂ组1020，卖出月饼使收益最大
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct mooncake
{
    /* data */
    int store;
    double amoney;
    double smoney;
}cake[1000];

bool cmp(mooncake a,mooncake b){
    return a.smoney>b.smoney;
}
int main()
{
    int n,need;
    cin>>n>>need;
    for(int i=0;i<n;i++){
        cin>>cake[i].store;
    }
    for(int j=0;j<n;j++){
        cin>>cake[j].amoney;
        cake[j].smoney=cake[j].amoney/(double)cake[j].store;
    }
    sort(cake,cake+n,cmp);
    double ans=0.0;
    for(int i=0;i<n;i++){
        if(cake[i].store<=need){
            ans+=cake[i].amoney;
            need-=cake[i].store;
        }else{
            ans+=cake[i].smoney*(double)need;
            break;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}