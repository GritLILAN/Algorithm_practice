#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 4e5 + 5;
//M又忘了开2倍了我tm服了，sb链式前向星狗都不用

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];
int res[3];
int minn = 0, maxx = 0;

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u, int c){
    color[u] = c;
    res[c]++;

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            dfs(j, 3 - c);
        }
    }

}


int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        add(a, b); add(b, a);
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