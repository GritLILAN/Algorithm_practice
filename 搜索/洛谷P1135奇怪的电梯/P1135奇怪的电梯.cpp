#include<bits/stdc++.h>
using namespace std;
const int N = 210;

int n,a,b;
int q[N];
int dis[N];
int res = 210;
int dir[2] = {1, -1};

void dfs(int u, int cnt){
    if(u == b){
        res = min(res, cnt);
        return;
    }

    dis[u] =  cnt;
    for(int i = 0; i < 2; i++){
        int nx = u + dir[i] * q[u];
        if(nx >= 1 && nx <= n && cnt + 1 < res && cnt + 1 < dis[nx]){
            dfs(nx, cnt + 1);
        }
    }

}



int main(){
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        cin >> q[i];
    }
    memset(dis, 0x3f, sizeof dis);

    dfs(a, 0);

    if(res == 210){
        cout << - 1 << endl; return 0;
    }
    cout << res << endl;



    return 0;
}