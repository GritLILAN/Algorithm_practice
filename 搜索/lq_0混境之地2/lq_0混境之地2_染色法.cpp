#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
//方法1：染色法

int dx[4] = {0,-1,0,1},dy[4] = {-1,0,1,0},n,m,xa,ya,xb,yb;
char mp[N][N];
bool ans;

void dfs(int x,int y,char c) {
    mp[x][y] = c;
    for(int i = 0; i < 4; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] == c || mp[nx][ny] == '#') continue;
    dfs(nx,ny,c);
    }
}

int main()
{
    cin>>n>>m>>xa>>ya>>xb>>yb;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) cin>>mp[i][j];
    }
  // 从起点开始染色@
    dfs(xa,ya,'@');
    if(mp[xb][yb] == '@') cout<<"Yes";
    else {
    // 如果没染到终点，则起点与终点不连通，再从终点开始染色&
    dfs(xb,yb,'&');
    // 开始遍历寻找是否存在隔开两种颜色的墙
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
      if(mp[i][j] == '#') {
        int a = 0,b = 0;
        for(int k = 0; k < 4; k ++) {
          int nx = i + dx[k], ny = j + dy[k];
          if(mp[nx][ny] == '@') a = 1;
          if(mp[nx][ny] == '&') b = 1;
        }
        if(a && b) {
          cout<<"Yes";
          return 0;
        }
      }
    cout<<"No";
  }
    return 0;
}