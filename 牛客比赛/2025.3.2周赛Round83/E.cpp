#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
const int INF = -1145141919810;

int n,k;
int a[N];
int dp[N][1005];
int res = INF;

signed main(){
    cin >> n >> k;
    memset(dp, INF, sizeof dp);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(i, k); j++){
            for(int p = max((ll)0, i - 6); p < i; p++){
                dp[i][j] = max(dp[i][j], dp[p][j - 1] + a[i]);
            }
        }
        res = max(res, dp[i][k]);
    }

    cout << res << endl;


    return 0;
}