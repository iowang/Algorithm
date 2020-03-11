// 经典八皇后问题求解
#include <iostream>
#include <cmath>
using namespace std;
int n;
int ans;
int used[100] = {0}, p[100];
// p[i]=j代表第i行第j列放置皇后
// index代表放置第几行
void solve(int index)
{
    if (index == n + 1)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    { //表示放置第几行
        if (!used[i])
        {
            bool flag = true;
            for (int j = 1; j < index; j++)
            {
                if (abs(index - j) == abs(i - p[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                p[index] = i;
                used[i] = 1;
                solve(index + 1);
                used[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    solve(1);
    cout << ans << endl;
    return 0;
}