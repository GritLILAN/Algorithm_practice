#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 510;
const int M = 2 * N * N;

int n, m, s, d;
int cnt[N];
int h[N], ne[M], e[M], w[M], idx;
int dist[N];
bool st[N];
int num[N];
int pre[N];
int road[N];//从s到i最短路径的条数

void add(int a, int b, int c){
    e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx++; 
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    dist[s] = 0;
    pre[s] = -1;
    road[s] = 1;
    num[s] = cnt[s];
    heap.push({0, s});

    while(heap.size()){
        auto u = heap.top();
        heap.pop();
        int distance = u.first, ver = u.second;

        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > distance + w[i]){
                road[j] = road[ver];
                num[j] = num[ver] + cnt[j];
                pre[j] = ver;
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
            else if(dist[j] == distance + w[i]){
                road[j] = road[j] +  road[ver];
                if(num[j] < num[ver] + cnt[j]){
                    num[j] = num[ver] + cnt[j];
                    pre[j] = ver;
                }
            }
        }
    }
}


signed main(){
    cin >> n >> m >> s >> d;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; i++) cin >> cnt[i];

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    dijkstra();

    cout << road[d] << ' ' << num[d] << endl;
    vector<int> path;
    path.push_back(d);
    for(int i = pre[d]; i != -1; i = pre[i]){
        path.push_back(i);
    }
    
    cout << s;
    for(int i = path.size() - 2; i >= 0; i--) cout << ' ' << path[i];

    return 0;
}