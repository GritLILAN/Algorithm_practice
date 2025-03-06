#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 150010;

int n,m;
int h[N], e[N], ne[N], w[N], idx;
int dis[N];
bool st[N];


void add(int a, int b, int c){
    e[idx] = b; ne[idx] = h[a]; w[idx] = c; h[a] = idx++;
}

int dijkstra(){
    dis[1] = 0;
    //定义小根堆，pair第一项存距离
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        
        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dis[j] > distance + w[i]){
                dis[j] = distance + w[i];
                heap.push({dis[j], j});
            }
        }

    }

    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(dis, 0x3f, sizeof dis);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        add(a,b,c);
    }

    cout << dijkstra();




    return 0;
}