#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n, m;
vector<int> ne[N];
bool st[N];


void dfs(int u){
    st[u] = true;
    cout << u << ' ';

    for(int i = 0; i < ne[u].size(); i++){
        int j = ne[u][i];
        if(st[j]) continue;
        dfs(j);
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    st[u] = true;

    while(q.size()){
        auto t = q.front();
        q.pop();
        cout << t << ' ';

        for(int i = 0; i < ne[t].size(); i++){
            int j = ne[t][i];
            if(st[j]) continue;
            st[j] = true;
            q.push(j);
        }
    }

}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        ne[a].push_back(b);
    }

    for(int i = 1; i <= n; i++)
        sort(ne[i].begin(), ne[i].end());

    dfs(1);
    cout << endl;
    memset(st, false, sizeof st);
    bfs(1);



    return 0;
}