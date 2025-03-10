#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
int h[N], e[N], ne[N], idx;
bool st[N];
vector<int> path;
set<int> s;
int res = 0;

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u){
    st[u] = true;
    
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(st[j]) continue;
        if(a[j]){
            for(int i = 0; i < path.size(); i++){
                s.insert(path[i]);
            }
            dfs(j);
        }
        else{
            path.push_back(j);
            dfs(j);
        }
    }

    if(a[u] == 0) path.pop_back();

}


int main(){
    memset(h, -1, sizeof h);
    cin >> n;
    int root = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!root && a[i] == 1) root = i;
    }
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        add(a,b); add(b,a);
    }

    dfs(root);

    cout << s.size() << endl;


    return 0;
}