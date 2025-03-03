#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;

int n,k;
int a[N];
int dp[N];
int sum = 0;
int res = 0;

void dfs(int u, int index){
    if(u == k){
        res = max(res, sum);
        return;
    }
    if(u < k && index ==n) return;

    for(int i = 1; i <= 6; i++){
        int nx = index + i;
        if(nx > n) continue;
        sum += a[nx];
        dfs(u + 1, nx);
        sum -= a[nx];
    }
}

signed main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dfs(0, 0);


    cout << res << endl;


    return 0;
}