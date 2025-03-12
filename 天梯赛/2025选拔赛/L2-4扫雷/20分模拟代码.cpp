#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 15;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

struct node{
    int x, y;
    char c;
};
int n, m;
char s[N][N];
queue<node> q;

bool check(){
    while(q.size()){
        auto t = q.front();
        q.pop();
        vector<PII> loc;
        int x = t.x, y = t.y;
        int num = t.c - '0';
        int cnt = 0;//记录?的个数
        int bomb = 0;//记录炸弹个数
        for(int i = 0; i < 8; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if(s[xx][yy] == '*') bomb++;
            if(s[xx][yy] == '?') {
                cnt++; loc.push_back({xx, yy});
            }
        }
        if(cnt + bomb == num){
            for(int i = 0; i < loc.size(); i++){
                int x = loc[i].first, y = loc[i].second;
                s[x][y] = '*';
            }
        }
        else if(cnt + bomb < num) return false;
        else{
            if(bomb == num){
                for(int i = 0; i < loc.size(); i++){
                    int x = loc[i].first, y = loc[i].second;
                    s[x][y] = '.';
                }
            }
            else if(bomb > num) return false;
            else{

            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '?') return false;
        }
    }
    return true;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> s[i][j];
                if(s[i][j] >= '0' && s[i][j] <= '8') q.push({i, j, s[i][j]});
            }
        }

        if(check()) cout << "YES" << endl;
        else cout << "NO" << endl;

    }




    return 0;
}