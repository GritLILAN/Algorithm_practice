#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e5 + 5;
//不可能路径设置成负无穷

int n, k;
int a[N][2];
int dp[N][2];

signed main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i][0];
    for(int i = 1; i <= n; i++) cin >> a[i][1];

    dp[1][0] = a[1][0];
    dp[1][1] = -1e18;
    for(int i = 2; i <=n; i++){
        for(int j = 0; j < 2; j++){
            if(dp[i - 1][!j] < k) dp[i - 1][!j] = -1e18;
            //dp[i][j] = a[i][j] + max(dp[i - 1][j], (int)(dp[i - 1][!j] >= k ? dp[i - 1][!j] - k : -1e18));
            dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][!j] - k);
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}