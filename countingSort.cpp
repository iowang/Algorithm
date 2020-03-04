/*
    计数排序在后半段有点饶人，寿险C数组的位置存储的是A数组中元素的个数
    然后统计C数组中每个元素有多少个元素小于它，这是方便后面倒这写入B数组的时候保证正确位置
    例如4 5 0 3 1 5 0 5 其中5是最大元素有3个，所以C[5]==3,然而还要继续使用C[i]=C[i-1]+C[i]所以此时C[5]==8
    这样下面写入B数组的代码时候直接就是B[8]=5，同时C[5]--==7，于是下面再遇到5的时候就可以保证B[7]=5

*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100], b[100],c[100];
    for(int j=0;j<100;j++) c[j]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
    } 
    for(int i=1;i<100;i++) c[i]=c[i]+c[i-1];
    for(int j=n;j>=0;--j){
        b[c[a[j]]]=a[j];
        c[a[j]]--;
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;

}