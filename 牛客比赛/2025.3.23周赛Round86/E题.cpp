#include<bits/stdc++.h>
#define int long long
using namespace std;

void sovle(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int s = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s = max(s, a[i]);
    }
    sort(a.begin() + 1, a.end());

    vector<int> dp(n * s + 1);
    dp[0] = 1;
    int res = 1e18;
    for(int i = 1; i <= n; i++){
        for(int j = a[i] + 1; j <= s * n; j++){
            if(dp[j]){
                res = min(res, a[i] + j);
                break;
            }
        }
        for(int j = s * n; j >= a[i]; j--){
            dp[j] |= dp[j - a[i]];
        }
    }
    if(res > 1e17) res = -1;
    cout << res << endl;

}


signed main(){
    int t; cin >> t;
    while(t--){
        sovle();
    }

    return 0;
}