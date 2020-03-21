// 表达式求值，给一个表达式计算其值只有+-×/运算，计算结果精确到小数点后两位
// 中缀转后缀，计算后缀的值
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cstdio>
using namespace std;
struct node{
    double num;
    char op;
    bool flag;
};
string str;
stack<node> s;//用来存放操作符
queue<node>q;//用来存放后缀表达式
map<char,int> op;
void change(){
    double num;
    node temp;
    for(int i=0;i<str.length();){
        if(str[i]<='9'&&str[i]>='0'){
            temp.flag=true;
            temp.num=str[i++]-'0';
            while(i<str.length()&&str[i]<='9'&&str[i]>='0'){
                temp.num=temp.num*10+(str[i]-'0');
                i++;
            }
            q.push(temp);
        }else{
            temp.flag=false;
            while(!s.empty()&&op[str[i]]<=op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op=str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
double calculate(){
    node cur,temp;
    double temp1,temp2;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(cur.flag==true){
            s.push(cur);
        }else{
            temp1=s.top().num;
            s.pop();
            temp2=s.top().num;
            s.pop();
            temp.flag=true;
            if(cur.op=='+') temp.num=temp1+temp2;
            else if(cur.op=='-') temp.num=temp2-temp1;
            else if(cur.op=='*') temp.num=temp2*temp1;
            else temp.num=temp2/temp1;
            s.push(temp);
        }
    }
    return s.top().num;
}
int main()
{
    op['+']=op['-']=1;
    op['*']=op['/']=2;
   while(getline(cin,str),str!="0"){
       for(string::iterator it=str.end();it!=str.begin();it--){
           if(*it==' ')   str.erase(it);
       }
       while(!q.empty()) q.pop();
       change();
       printf("%.2lf\n",calculate());
   }
   return 0;
}