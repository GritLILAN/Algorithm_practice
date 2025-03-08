#include<bits/stdc++.h>
using namespace std;
const int N = 210;
const int INF = 1e9;

int n, m, Q;
int dis[N][N];

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
    cin >> n >> m >> Q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        dis[x][y] = min(dis[x][y], z);
    }

    floyd();

    while(Q--){
        int x, y;
        cin >> x >> y;
        if(dis[x][y] > INF / 2) cout << "impossible" << endl;
        else cout << dis[x][y] << endl;
    }



    return 0;
}