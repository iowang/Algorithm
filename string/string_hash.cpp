// 本题是使用字符串hash，给N个字符串固定长度为3，再给M个查询串
// 问查询串在N个字符串中出现的次数
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int hasha[30000];
int hash_func(string s,int num){
    int id=0;
    for(int i=0;i<num;i++){
        if(s[i]<='z'&&s[i]>='a'){
            id=id*26+(s[i]-'a');
        }
    }
    return id;
}
int main()
{
    int N,M,id;
    string s;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>s;
        id=hash_func(s,3);
        hasha[id]++;
    }
    for(int j=0;j<M;j++){
        cin>>s;
        id=hash_func(s,3);
        cout<<hasha[id]<<endl;
    }
    return 0;
}