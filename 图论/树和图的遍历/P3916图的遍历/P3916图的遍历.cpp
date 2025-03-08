#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
//反向建边

int n, m;
int h[N], e[N], ne[N], idx;
int mark[N];
bool st[N];

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u, int src){
    st[u] = true;

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(st[j]) continue;
        mark[j] = max(mark[j], src);
        dfs(j, src);
    }


}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        add(b, a);
    }

    for(int i = 1; i <= n; i++) mark[i] = i;
    for(int i = n; i >= 1; i--){
        dfs(i, i);
    }

    for(int i = 1; i <= n; i++){
        cout << mark[i] << ' ';
    }


    return 0;
}