#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 2e5 + 5;

int n, m;
int color[N];
int res[3];
int minn = 0, maxx = 0;
vector<int> eg[N];

void dfs(int u, int c){
    color[u] = c;
    res[c]++;

    for(int y : eg[u]){
        if(!color[y]) dfs(y, 3 - c);
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        eg[a].push_back(b); eg[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!color[i]) {
            dfs(i, 1);
            minn += min(res[1], res[2]);
            maxx += max(res[1], res[2]);
            res[1] = res[2] = 0;
        }
    }
    
    cout << minn << ' ' << maxx << endl;

    return 0;
}