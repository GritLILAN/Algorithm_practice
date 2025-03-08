#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 2e5 + 5;

int n, m, s;
int h[N], e[M], ne[M], w[M], idx;
int dis[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void dijkstra(){
    dis[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, s});

    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            //if(st[j]) continue;
            dis[j] = min(dis[j], distance + w[i]);
            heap.push({dis[j], j});
        }
    }

}

int main(){
    cin >> n >> m >> s;
    memset(h, -1, sizeof h);
    memset(dis, 0x3f,sizeof dis);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    dijkstra();

    for(int i = 1; i <= n; i++){
        cout << dis[i] << ' ';
    }

    return 0;
}