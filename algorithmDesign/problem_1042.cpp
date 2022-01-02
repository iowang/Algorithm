#include<iostream>
#include<vector>
using namespace std;
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int dp[400]={0};
    int maxx=days[days.size()-1];
    int minn=days[0];
    for(int day=maxx,i=days.size()-1;day>=minn&&i>=0;day--){
        if(day==days[i]){
            dp[day]=min(costs[0]+dp[day+1],costs[1]+dp[day+7]);
            dp[day]=min(dp[day],costs[2]+dp[day+30]);
            i--;
        }else{
            dp[day]=dp[day+1];
        }
    }
    return dp[minn];
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int daynum;
        cin>>daynum;
        vector<int> days;
        vector<int> costs;
        int a;
        for(int i=0;i<daynum;++i){
            cin>>a;
            days.push_back(a);
        }
        for(int j=0;j<3;++j){
            cin>>a;
            costs.push_back(a);
        }
        int ans=mincostTickets(days,costs);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}