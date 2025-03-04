#include<bits/stdc++.h>
using namespace std;
const int N = 25;

int n,k;
int a[N];
int res = 0;
bool st[N];

bool check(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int u, int index, int sum){
    if(u == k){
        //cout << "sum:" << sum << endl; 
        if(check(sum)) res++;
    }

    for(int i = index; i < n; i++){
        if(st[i]) continue;
        st[i] = true;
        dfs(u + 1, i, sum + a[i]);
        st[i] = false;
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    dfs(0, 0, 0);

    cout << res << endl;

    return 0;
}