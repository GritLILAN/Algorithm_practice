#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N  = 405;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int n, m, x, y;
int dis[N][N];
queue<PII> q;

void bfs(int x, int y){
    q.push({x, y});
    dis[x][y] = 0;

    while(q.size()){
        PII t = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int xx = t.first + dx[i], yy = t.second + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if(dis[xx][yy] != -1) continue;
            q.push({xx, yy});
            dis[xx][yy] = dis[t.first][t.second] + 1;
        }

    }

}


int main(){
    cin >> n >> m >> x >> y;

    memset(dis, -1, sizeof dis);

    bfs(x, y);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}