#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 15;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int n, m;
char g[N][N], f[N][N];
vector<PII> res;

bool check(int x, int y){
    int sum = 0;
    for(int i = 0; i < 8; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(f[xx][yy] == '*') sum++;
    }
    return sum == (f[x][y] - '0');
}

void sovle(){
    cin >> n >> m;
    res.clear();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
            if(g[i][j] == '?')
                res.push_back(make_pair(i, j));
        }
    int cnt = res.size();
    for(int bit = 0; bit < 1 << cnt; bit++){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                f[i][j] = g[i][j];
        for(int i = 0; i < cnt; i++){
            auto [x, y] = res[i];
            if(bit >> i & 1) f[x][y] = '*';
            else f[x][y] = '?';
        }

        bool flag = true;
        for(int i = 1; i <= n && flag; i++){
            for(int j = 1; j <= m; j++){
                if('0' <= f[i][j] && f[i][j] <='8' && !check(i ,j)){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        sovle();
    }







    return 0;
}