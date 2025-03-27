#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, m;
int w[N], v[N];
int dp[N][N];//dp[i][j]表示从前i个物品中选，最大体积不超过j时的最大价值

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - w[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    int res = 0;
    for(int j = 1; j <= m; j++){
        res = max(res, dp[n][j]);
    }
    cout << res << endl;


    return 0;
}