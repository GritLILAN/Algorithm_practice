#include<bits/stdc++.h>
using namespace std;
const int N = 25;
const int INF = 0x3f3f3f;

int s[4];
int t[4][N];
int res = 0;
int ans = INF;
int sum_l = 0, sum_r = 0;

void dfs(int index, int u){
    if(u == s[index]){
        ans = min(ans, max(sum_l, sum_r));
        return;
    }

    //用左脑做第u道题
    sum_l += t[index][u];
    dfs(index, u + 1);
    sum_l -= t[index][u];

    //用右脑做第u道题
    sum_r += t[index][u];
    dfs(index, u + 1);
    sum_r -= t[index][u];

}


int main(){
    for(int i = 0; i < 4; i++) cin >> s[i];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < s[i]; j++){
            cin >> t[i][j];
        }
    }
    
    for(int i = 0; i < 4; i++){
        ans = INF;
        dfs(i, 0);
        res += ans;
    }

    cout << res << endl;


    return 0;
}

