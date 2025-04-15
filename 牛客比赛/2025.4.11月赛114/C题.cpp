#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, x;
vector<vector<int> > ne(N);
bool st[N];

bool bfs(){
    queue<int> q;
    q.push(x);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < ne[u].size(); i++){
            int j = ne[u][i];
            if(j == x) return true;
            q.push(j);
        }
    }
    return false;
}

int main(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        ne[u].push_back(i);
    }


    bool f = bfs();
    
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}