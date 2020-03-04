//逆波兰表达式求值
#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    stack<int> ans;
    string s;
    getline(cin,s);
    // cout<<s<<endl;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]==' ') continue;
        else if(s[i]>='0' && s[i]<='9'){
            int k=s[i]-'0';
            ans.push(k);
            // cout<<ans.top()<<" ";
        }else if(s[i]=='+'){
            int a=ans.top();
            ans.pop();
            int b=ans.top();
            ans.pop();
            ans.push(a+b);
            // cout<<ans.top()<<" ";
        }else if(s[i]=='-'){
            int a=ans.top();
            ans.pop();
            int b=ans.top();
            ans.pop();
            ans.push(b-a);
            // cout<<ans.top()<<" ";
        }else if(s[i]=='*'){
            int a=ans.top();
            ans.pop();
            int b=ans.top();
            ans.pop();
            ans.push(a*b);
            // cout<<ans.top()<<" ";
        }else{
            int a=ans.top();
            ans.pop();
            int b=ans.top();
            ans.pop();
            ans.push(b/a);
            // cout<<ans.top()<<" ";
        }

    }
    cout<<ans.top()<<endl;
    return 0;
}