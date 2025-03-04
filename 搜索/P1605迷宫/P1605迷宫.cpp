#include<bits/stdc++.h>
using namespace std;
const int  N = 10;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n, m, t;
int sx, sy, fx, fy;
int mp[N][N];
bool st[N][N];
int res = 0;

void dfs(int x, int y){
    if(x == fx && y == fy){
        res++;
        return;
    }

    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 1 || xx > n || yy < 1 || yy > m || st[xx][yy]) continue;
        if(mp[xx][yy]) continue;

        st[xx][yy] = true;
        dfs(xx, yy);
        st[xx][yy] = false;
    }
}

int main(){
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    for(int i = 0; i < t; i++){
        int tx, ty; cin >> tx >> ty;
        mp[tx][ty] = 1;
    }

    st[sx][sy] = true;
    dfs(sx, sy);

    cout << res << endl;

    return 0;
}