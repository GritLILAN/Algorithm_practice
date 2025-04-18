#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
int h[N], e[N], ne[N], idx;
int dis[N];
int q[N];

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int bfs(){
    int hh = 0, tt = 0;
    q[0] = 1;

    while(hh <= tt){
        int t = q[hh ++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dis[j] == -1){
                dis[j] = dis[t] + 1;
                q[++tt] = j;
            }
        }
    }

    return dis[n];
}


int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(dis, -1, sizeof dis);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        add(a, b);
    }

    dis[1] = 0;

    cout << bfs() << endl;


    return 0;
}