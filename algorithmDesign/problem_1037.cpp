//二分图的最大匹配问题：匈牙利算法
#include<iostream>
using namespace std;
int T, n, m, k;
int key = 0;
bool match[51][51], used[51];
int girl[51];
bool find(int x);
int main()
{	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> m;//n位男嘉宾和m位女嘉宾(n,m<=50)
		for (int j = 1; j <= 50; j++)
			for (int w = 1; w <= 50; w++)
			{
				match[j][w] = false; used[w] = false; girl[w] = 0;
			}
		int succ = 0, x;
		for (int j = 1; j <= n; j++)//每个男嘉宾中意的女嘉宾
		{
			cin >> k;
			for (int w = 0; w < k; w++)
			{
				cin >> x; match[j][x] = true;//男嘉宾j中意女嘉宾x
			}
		}
		for (int j = 1; j <= n; j++)
		{
			for (int w = 1; w <= m; w++)
				used[w] = false;//每个男嘉宾只需匹配一次女嘉宾即可
			if (find(j)) succ++;
		}
		cout << succ << endl;
	}
	return 0;
}
bool find(int x)
{
	for (int i = 1; i <= m; i++)//扫描每位女嘉宾
	{
		if (match[x][i] == true && used[i] == false)
		{
			used[i] = true;
			if (girl[i] == 0 || find(girl[i]))
			{
				girl[i] = x;return true;
			}
		}
	}
	return false;
}
