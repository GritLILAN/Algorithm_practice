#include<bits/stdc++.h>
using namespace std;
const int N = 15;

int n;
int s[N],b[N];
int res = 0x3f3f3f3f;

void dfs(int u, int ss, int bb, int cnt){
    //cout << u << ' ' << ss << ' ' << bb << endl;
    if(u == n){
        if(cnt == 0) return;
        int ans = abs(ss - bb);
        res = min(res, ans);
        return;
    }
    //选
    dfs(u + 1, ss * s[u], bb + b[u], cnt + 1);
    //不选
    dfs(u + 1, ss, bb, cnt);

}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> b[i];
    }

    dfs(0, 1, 0, 0);

    cout << res << endl;

    return 0;
}