#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 110;
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};
int n;
char a[N][N];
string tmp[N];
bool st[N][N];
string s = "yizhong";
char res[N][N];
vector<PII> loc;

void dfs(int x, int y, int cnt, int dir){
    //cout << cnt << endl;
    if(dir == -1){
        for(int i = 0; i < 8; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
            if(a[xx][yy] == s[1]){
                //cout << xx << ' ' << yy << endl;
                //cout << "s[1]" << endl;
                loc.push_back({xx,yy});
                dfs(xx, yy, cnt + 1, i);
                loc.pop_back();
            }
        }
    }
    else{
        if(cnt == 6){
            //处理res数组
            //cout << "yes" << endl;
            for(int i = 0 ; i < loc.size(); i++){
                res[loc[i].first][loc[i].second] = s[i];
            }
            return;
        }
        int xx = x + dx[dir], yy = y + dy[dir];
        if(xx < 1 || xx > n || yy < 1 || yy > n) return;
        if(a[xx][yy] == s[cnt + 1]){
            loc.push_back({xx, yy});
            dfs(xx, yy, cnt + 1, dir);
            loc.pop_back();
        }
    }

 
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> tmp[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            res[i][j] = '*';


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = tmp[i][j - 1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 'y'){
                loc.clear();
                loc.push_back({i,j});
                dfs(i, j, 0, -1);
            }
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << res[i][j];
        }
        cout << endl;
    }




    return 0;
}