// 本题用二分法求得根号2的近似值
#include<iostream>
#include<cmath>
using namespace std;
const double eps=1e-5;
double f(double x){
    return x*x;
}
int main()
{
    double left=1,right=2,mid;
    while(right-left>eps){
        mid=(right+left)/2;
        if(f(mid)>2){
            right=mid;
        }else{
            left=mid;
        }
    }
    cout<<mid<<endl;
    return 0;
}