#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
//方法1：染色法

int dx[4] = {0,-1,0,1},dy[4] = {-1,0,1,0},n,m,xa,ya,xb,yb;
char mp[N][N];

void dfs(int x, int y, char c){
  mp[x][y] = c;
  for(int i = 0 ; i < 4; i++){
    int xx = x + dx[i], yy = y + dy[i];
    if(xx > n || xx < 1 || yy > m || yy < 1) continue;
    if(mp[xx][yy] == '#' || mp[xx][yy] == c) continue;

    dfs(xx, yy, c);
  }

}

int main()
{
    cin>>n>>m>>xa>>ya>>xb>>yb;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) cin>>mp[i][j];
    }

    dfs(xa,ya,'@');
    if(mp[xb][yb] == '@'){
      cout << "Yes" << endl;
      return 0;
    }
    else{
      dfs(xb,yb,'&');
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
          if(mp[i][j] == '#'){
            int a = 0, b = 0;
            for(int k = 0; k < 4; k++){
              int xx = i + dx[k], yy = j + dy[k];
              if(mp[xx][yy] == '@') a = 1;
              if(mp[xx][yy] == '&') b = 1;
            }
            if(a == 1 && b == 1){
              cout << "Yes" << endl;
              return 0;
            }
          }
        }
      }
    }
  
    cout << "No" << endl;

    return 0;
}