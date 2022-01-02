#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> used(10001);
struct point{
    int x,y;
};
const double inf=1e-10;
bool cmp(point a,point b){
    return a.x<b.x;
}
void isCovered(vector<point>& vc,double x,int d){
    for(int i=0;i<vc.size();++i){
        if(!used[i]){
            point p1=vc[i];
            if((p1.x-x)*(p1.x-x)+(p1.y*p1.y)-(d*d)<inf){
                used[i]=1;
            }else{
                continue;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,d;
        point p;
        int ans=0;
        vector<point> vc;
        cin>>n>>d;
        for(int i=0;i<n;++i){
            cin>>p.x>>p.y;
            vc.push_back(p);
            used[i]=0;
        }
        // cout<<used[1]<<endl;
        sort(vc.begin(),vc.end(),cmp);
        for(int i=0;i<n;++i){
            if(!used[i]){
                point p1=vc[i];
                double x=sqrt(d*d-p1.y*p1.y)+p1.x;
                ans++;
                used[i]=1;
                isCovered(vc,x,d);
            }
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}