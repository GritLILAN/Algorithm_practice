#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 310;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int m;
int rock[N][N];
int dis[N][N];
bool st[N][N];

int cal(int a){
    if(a == -1) return 9999;
    return a;
}

bool bfs(){
    queue<PII> q;
    q.push({0,0});
    st[0][0] = true;
    while(q.size()){
        PII u = q.front();
        q.pop();
        int x = u.first, y = u.second;

        if(rock[x][y] == -1){
            cout << dis[x][y] << endl; return true;;
        }
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            int tt = dis[x][y] + 1;
            if(xx < 0 || yy < 0 || st[xx][yy]) continue;
            if(tt >= cal(rock[xx][yy])) continue;
            q.push({xx, yy});
            dis[xx][yy] = dis[x][y] + 1;
            st[xx][yy] = true;
        }
    }
    return false;
}


int main(){
    cin >> m;
    memset(rock, -1, sizeof rock);
    for(int i = 0; i < m; i++){
        int x, y, t;
        cin >> x >> y >> t;
        if(rock[x][y] == -1 || rock[x][y] > t){
            rock[x][y] = t;
        }

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && yy >= 0 && (rock[xx][yy] == -1 || rock[xx][yy] > t)) 
                rock[xx][yy] = t;
        }
    }
    
    if(!bfs()) cout << -1 << endl;    


    return 0;
}