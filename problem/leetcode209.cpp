// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。
// // 如果不存在符合条件的连续子数组，返回 0。
// 输入: s = 7, nums = [2,3,1,2,4,3]
// 输出: 2
// 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
#include<iostream>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int nums[100];
    for(int k=0;k<n;k++){
        cin>>nums[k];
    }
    for(int k=0;k<n;k++){
        if(nums[k]==s){
            cout<<1<<endl;
            return 0;
        }
    }
    int i,j;
    i=0;j=i+1;
    int temp=0;
    int ans=99999999;
    temp=nums[i]+nums[j];
    while(j<n){
        if(temp==s){
            if(ans>(j-i+1)){
                ans=(j-i)+1;
            }
            j++;
            temp-=nums[i];
            i++;
            if(j<n)
            temp+=nums[j];
        }
        else if(temp<s){
            j++;
            if(j<n)
            temp+=nums[j];
        }
        else{
            temp-=nums[i];
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}