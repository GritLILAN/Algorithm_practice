#include<bits/stdc++.h>
using namespace std;
const int N = 510;

int n, m;
int g[N][N];
int dis[N];
bool st[N];//某个点是否加入集合S

int dijkstra(){
    dis[1] = 0;
    for(int i = 0; i < n; i++){
        int t = -1;//t表示第i轮要找的最近的点
        for(int j = 1; j <= n; j++){
            if(st[j]) continue;
            if(t == -1 || dis[j] < dis[t]){
                t = j;
            }
        }

        st[t] = true;

        for(int j = 1; j <= n; j++){
            if(dis[j] > dis[t] + g[t][j]){
                dis[j] = dis[t] + g[t][j];
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}


int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(dis, 0x3f, sizeof dis);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }


    cout << dijkstra() << endl;

    return 0;
}