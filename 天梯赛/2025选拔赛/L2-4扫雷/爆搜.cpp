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
vector<PII> loc;
vector<node> number;
bool ans = false;

bool check(){
    for(int i = 0; i < number.size(); i++){
        int cnt = 0;
        int x = number[i].x, y = number[i].y;
        int num = number[i].c - '0';
        for(int j = 0; j < 8; j++){
            int xx = x + dx[j], yy = y + dy[j];
            if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if(s[xx][yy] == '*') cnt++;
        }
        //cout << "cnt " << cnt << endl;
        if(cnt != num) return false;
    }
    return true;
}

void dfs(int u){
    if(u == loc.size()){

        // for(int i = 1; i <= n; i++){
        //     for(int j =1; j <= m; j++){
        //         cout << s[i][j];
        //     }
        //     cout << endl;
        // }

        if(check()) ans = true;
        return;
    }
    
    int x = loc[u].first, y = loc[u].second;
    //cout << x << ' ' << y << endl;
    s[x][y] = '.';
    dfs(u + 1);
    s[x][y] = '?';

    s[x][y] = '*';
    dfs(u + 1);
    s[x][y] = '?';

    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        ans = false;
        number.clear();
        loc.clear();
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> s[i][j];
                if(s[i][j] >= '0' && s[i][j] <= '8') number.push_back({i, j, s[i][j]});
                if(s[i][j] == '?') loc.push_back({i, j});
            }
        }

        // cout << loc.size() << endl;
        // for(int i = 0; i < loc.size(); i++){
        //     cout << loc[i].first << ' ' << loc[i].second<< endl;
        // }

        dfs(0);

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;



    }




    return 0;
}