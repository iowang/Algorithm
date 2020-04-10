/**
 * 最小生成树算法kuskal算法，根据边来
*/
#include <cstdio>
#include <cstdlib>
#include<algorithm>
#include<iostream>
#define MAXN 10000 + 10
using namespace std;
 
int par[MAXN], Rank[MAXN];
typedef struct{
    int a, b, price;
}Node;
Node a[MAXN];
 
int cmp(const void*a, const void *b){
    return ((Node*)a)->price - ((Node*)b)->price;
}
void Init(int n){
    for(int i = 0; i < n; i++){
        Rank[i] = 0;
        par[i] = i;
    }
}
 
int find(int x){
    int root = x;
    while(root != par[root]) root = par[root];
    while(x != root){
        int t = par[x];
        par[x] = root;
        x = t;
    }
    return root;
}
 
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(Rank[x] < Rank[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}
//n为边的数量，m为村庄的数量
int Kruskal(int n, int m){
    int nEdge = 0, res = 0;
    //将边按照权值从小到大排序
    qsort(a, n, sizeof(a[0]), cmp);
    for(int i = 0; i < n && nEdge != m - 1; i++){
        //判断当前这条边的两个端点是否属于同一棵树
        if(find(a[i].a) != find(a[i].b)){
            unite(a[i].a, a[i].b);
            res += a[i].price;
            nEdge++;
        }
    }
    //如果加入边的数量小于m - 1,则表明该无向图不连通,等价于不存在最小生成树
    if(nEdge < m-1) res = -1;
    return res;
}
int main(){
    int n, m, ans;
    while(scanf("%d%d", &n, &m), n){
        Init(m);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].price);
            //将村庄编号变为0~m-1（这个仅仅只是个人习惯，并非必要的）
            a[i].a--;
            a[i].b--;
        }
        ans = Kruskal(n, m);
        if(ans == -1) printf("?\n");
        else printf("%d\n", ans);
    }
    return 0;
}