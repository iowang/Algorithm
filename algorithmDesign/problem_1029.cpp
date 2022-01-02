#include <iostream>
#include <vector>
const int INF = 1e7;

using namespace std;
int nn, m;
vector<vector<int>> Init() {
    cin >> nn >> m;
    vector<vector<int>> graph(nn+1, vector<int>(nn+1, INF));
    int start, end, wet;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> wet;
        graph[start][end] = min(wet,graph[start][end]);
        graph[end][start] = min(wet,graph[end][start]);
    }
    return graph;
}

int Prim(vector<vector<int>>& c, int u) {
    int num=1;
    int n = c.size() - 1;
    vector<int> lowcost(n+1);
    vector<int> closest(n+1);
    vector<bool> s(n+1);

    s[u] = true;
    for (int i = 1; i <= n; i++) {
        if (i != u) {
            lowcost[i] = c[u][i];
            closest[i] = u;
            s[i] = false;
        }
        else
            lowcost[i] = 0;
    }


    for (int i = 0; i < n-1; i++) {
        // 2.找最小
        int tmp = INF, t = u;
        for (int j = 1; j <= n; j++) {
            if (!s[j] && (lowcost[j] < tmp)) {   //!s[j]表示j节点V-U集合中
                t = j;
                tmp = lowcost[j];
            }
        }
        // 找不到，跳出循环
        if (t == u) break;

        // 将t加入集合U
        s[t] = true;  
        num++;
        // 3.更新
        for (int j = 1; j <= n; j++) {
            if ((!s[j]) && (c[t][j] < lowcost[j])) {
                lowcost[j] = c[t][j];
                closest[j] = t;
            }
        }
    }

    int totalcost = 0;
    for (int i = 1; i <= n; i++) {
        totalcost += lowcost[i];
    }
    if(num==nn) return totalcost;
    else return -1;
}

// test main()
int main() {
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> graph = Init();
        int weight = Prim(graph, 1); // 1表示从1开始找
        cout  << weight << endl;
    }
    system("pause");
    return 0;
}