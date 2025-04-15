#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
int res = 0;
bool st[N];

void dfs(int u, int cnt){
    if(u == n){
        res = max(res, cnt);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(st[i]) continue;
        st[i] = true;
        if(a[i] == u + 1) dfs(u + 1, cnt + a[i]);
        else dfs(u + 1, cnt);
        st[i] = false;
    }


}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    dfs(0, 0);

    cout << res << endl;
    
    return 0;
}