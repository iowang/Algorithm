/* 
    PAT RANKING
    给n个学生信息，信息由准考证号，成绩构成，输出信息由准考证号，排名，考场号，场内排名构成
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct student
{
    /* data */
    string num;
    int socre;
    int arank;
    int knum;
    int krank;
}stus[100];
bool cmp(student a,student b){
    if(a.socre!=b.socre){
        return a.socre>b.socre;
    }
    return a.num<b.num;
}

int main()
{
    int n;
    cin>>n;
    int k,i;
    int temp=0;
    for(int j=1;j<=n;j++){
        cin>>k;
        for(i=temp+1;i<=temp+k;i++){
            cin>>stus[i].num>>stus[i].socre;
            stus[i].knum=j;
        }
        sort(stus+temp+1,stus+i,cmp);
        int s=1;
        for(int t=temp+1;t<=i-1;t++){
            if(t==temp+1){
                stus[t].krank=s;
                s++;
            }
            else if(stus[t].socre==stus[t-1].socre){
                stus[t].krank=stus[t-1].krank;
                s++;
            }else{
                stus[t].krank=s;
                s++;
            }
        }
        temp=i-1;
    }
    sort(stus+1,stus+temp+1,cmp);
    for(int u=1;u<=temp;u++){
        if(u==1){
            stus[u].arank=u;
        }
        else if(stus[u].socre==stus[u-1].socre){
            stus[u].arank=stus[u-1].arank;
        }else{
            stus[u].arank=u;
        }
    }
    cout<<temp<<endl;
    for(int u=1;u<=temp;u++){
        cout<<stus[u].num<<" "<<stus[u].arank<<" "<<stus[u].knum<<" "<<stus[u].krank<<endl;
    }
    return 0;
}