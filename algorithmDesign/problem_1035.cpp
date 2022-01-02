#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long c[100001];
        long long y[100001];
        long long z[100001];
        for(int i=0;i<n;++i){
            cin>>c[i];
            z[i]=c[i];
        }
        for(int i=0;i<n;++i) cin>>y[i];
        long long cost=0;
        cost+=c[0]*y[0];
        for(int i=1;i<n;++i){
            z[i]=min(z[i],z[i-1]+1);
            cost+=z[i]*y[i];
        }
        
        //上面是方法一，注释掉的为方法二，两个方法都可以accept
        /*int start=0,next=0;
        long long curprice=999999;
        long long k=0;
        while(start<n&&next<n){
            if(next==0){
                curprice=c[next];
                cost+=(c[next]*y[next]);
                next++;
                k++;
            }
            else if(next<n&&c[next]>=(curprice+k)){
                cost+=(curprice+k)*y[next];
                next++;k++;
            }
            else if(next<n&&c[next]<(curprice+k)){
                curprice=c[next];
                k=0;
                cost+=(curprice+k)*y[next];
                next++;k++;
            }
        }*/
        
        
        cout<<cost<<endl;
    }
    system("pause");
    return 0;
}