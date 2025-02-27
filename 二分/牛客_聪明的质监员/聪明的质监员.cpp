#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

ll n, m, S;
int w[N], v[N];
int L[N], R[N];
ll sum[N];//v的前缀和
ll cnt[N];//统计满足w[j]>W的数量

ll cal(int k){
    memset(sum, 0, sizeof sum);
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= n; i++){
        if(w[i] >= k){
            sum[i] = sum[i - 1] + v[i];
            cnt[i] = cnt[i - 1] + 1;
        }
        else{
            sum[i] = sum[i - 1];
            cnt[i] = cnt[i - 1];
        }
    }

    ll Y = 0;
    for(int i = 1; i <= m; i++){
        Y += (sum[R[i]] - sum[L[i] - 1]) * (cnt[R[i]] - cnt[L[i] - 1]);
    }

    return Y;
}


int main(){
    cin >> n >> m >> S;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= m; i++) cin >> L[i] >> R[i];

    int l = 0, r = 1e6 + 10;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(cal(mid) >= S) l = mid;
        else r = mid - 1;
    }

    ll res = min(abs(cal(l) - S), abs(cal(l + 1) - S));
    cout << res << endl;

    return 0;
}