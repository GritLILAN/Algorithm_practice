#include<bits/stdc++.h>
using namespace std;
const int N = 110;
const int M = N * N;

int dis[N];
int n;
int h[N], e[M], ne[M], w[N], idx;
bool st[N];
int ans = 0x3f3f3f3f;

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int bfs(int x){
    queue<int> q;
    q.push(x);
    dis[x] = 0;

    int res = 0;
    while(q.size()){
        auto t = q.front();
        q.pop();
        res += dis[t] * w[t];

        st[t] = true;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            dis[j] = dis[t] + 1;
            if(st[j]) continue;
            q.push(j);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << dis[i] << ' ';
    // }cout << endl;
    

    return res;
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        int l, r; cin >> l >> r;
        if(l){
            add(i, l), add(l, i);
        }
        if(r){
            add(i, r), add(r, i);
        }
    }

    for(int i = 1; i <= n; i++){
        memset(dis, 0, sizeof dis);
        memset(st, false, sizeof st);
        ans = min(ans, bfs(i));
    }

    cout << ans << endl;

    return 0;
}