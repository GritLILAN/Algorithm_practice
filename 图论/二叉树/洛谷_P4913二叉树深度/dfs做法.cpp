#include<bits/stdc++.h>
using namespace std;
const int  N = 1e6 + 5;

int n;
int lchild[N], rchild[N];
int res = 0;

void dfs(int u, int cnt){
    if(u == 0) return;
    res = max(res, cnt);

    dfs(lchild[u], cnt + 1);
    dfs(rchild[u], cnt + 1);
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> lchild[i] >> rchild[i];
    }

    dfs(1, 1);

    cout << res << endl;

    return 0;
}


