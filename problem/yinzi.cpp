// 给一个数，求其质因子，如8=2*2*2
#include<iostream>
using namespace std;
int yinzi[10]={2,3,5,7,11,13,17,19,23,29};
struct node{
    int x;
    int cnt;
}func[10];
int main()
{
    int n,temp;
    cin>>n;
    temp=n;
    int num=0;
    int i=0;
    for(int j=0;j<10;j++){
        func[j].x=func[j].cnt=0;
    }
    while(true){
        if(n<yinzi[i]) break;
        if((n>yinzi[i])&&(n%yinzi[i]!=0)) i++;
        while((n%yinzi[i])==0){
            func[i].x=yinzi[i];
            func[i].cnt++;
            num++;
            n/=yinzi[i];
            if(n>yinzi[i]) break;
        }
    }
    // cout<<num;
    cout<<temp<<'=';
    for(int j=0;j<10;j++){
        if(func[j].cnt!=0){
            while(func[j].cnt!=0&&num!=1){
                cout<<func[j].x<<'*';
                func[j].cnt--;
                num--;
            }
            // cout<<"?";
            if(num==1&&func[j].cnt!=0){
                cout<<func[j].x;
                func[j].cnt--;
                num--;
            }
        }
    }
    cout<<endl;
    return 0;
}