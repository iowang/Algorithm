#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	string s;
	int ans,len;
	while(n--){
		ans=0;
		getline(cin,s);
		len=s.length();
		for(int i=0;i<len;i++){
			if(s[i]>='0'&&s[i]<='9') ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
