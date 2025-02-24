#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

//方法2：记忆化搜索
int n,m;
int ax,ay,bx,by;
char mp[N][N];
int dp[N][N][2]; //dp数组表示从起点到(x,y)在消耗/不消耗超能力的情况况下，能否到达终点
//dp[x][y][0]表示到(x,y)没有使用过超能力破墙
bool st[N][N];

bool dfs(int x, int y, int flag){
    if(x == bx && y == by) return dp[x][y][flag] = true;
    if(dp[x][y][flag] != -1) return dp[x][y][flag];

    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx > n || xx < 1 || yy > m || yy < 1 || st[xx][yy]) continue;
        
        st[xx][yy] = true;
        
        if(flag){
            if(mp[xx][yy] == '.' && dfs(xx, yy, 1)){
                dp[x][y][1] = true; return true;
            }      
        }
        else{
            if(mp[xx][yy] == '.' && dfs(xx, yy, 0)){
                dp[x][y][0] = true; return true;
            }     
            if(mp[xx][yy] == '#' && dfs(xx, yy, 1)){
                dp[x][y][1] = true; return true; 
            }     
        }
        st[xx][yy] = false;
    }

    dp[x][y][flag] = false;
    return false;
}


int main(){
    cin >> n >> m;
    cin >> ax >> ay >> bx >> by;
    for(int i = 1 ; i <= n; i ++)
        for(int j = 1; j <= m; j++)
            cin >> mp[i][j];

    memset(dp, -1, sizeof dp);
    
    if(dfs(ax, ay, 0) == true){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;


    return 0;
}