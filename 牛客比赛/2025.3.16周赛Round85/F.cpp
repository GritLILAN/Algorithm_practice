#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n, k;
vector<int> g[N];
int siz[N];//节点i的子树中与i联通的红色节点个数
int use = 0;

void dfs(int u, int f, int mid){
     

    for(int v : g[u]){
        if(v == f) continue;
        dfs(v, u, mid);
        siz[u] += siz[v];
    }
    if(siz[u] > mid){
        use++;//紫色节点+1
        siz[u] = 0;//标记这个子树为独立的连通块
    }
}

bool check(int mid){
    use = 0;
    for(int i = 1; i <= n; i++) siz[i] = 1;
    dfs(1, 0, mid);
    return use <= k;//染紫的节点数少，说明连通块大小mid太大
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int l = 0, r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;

    return 0;
}
