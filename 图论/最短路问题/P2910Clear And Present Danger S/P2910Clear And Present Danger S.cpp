#include<bits/stdc++.h>
using namespace std;
const int N = 110;
const int M = 1e4 + 5;
typedef pair<int, int> PII;

int n, m;
int path[M];
int dis[N][N];
queue<PII> q;

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
              dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);  
            }
        }
    }

}

int main(){
    cin >> n >> m;
    int last = 0;
    for(int i = 0; i < m; i++){
        int x;  cin >> x;
        if(i == 0){
            last = x; continue;
        }
        q.push({last, x});
        last = x;

      
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> dis[i][j];
        }
    }

    floyd();

    int res = 0;
    while(q.size()){
        auto t = q.front(); q.pop();
        int l = t.first, r = t.second;
        //cout << l  <<' ' << r << endl;
        res += dis[l][r];
    }

    cout << res << endl;

    return 0;
}