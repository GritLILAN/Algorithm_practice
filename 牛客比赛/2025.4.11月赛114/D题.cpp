#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
//由于存在负数，孙权可以选择不选负数
//预处理前后缀的时候需要记录历史最大前缀和（后缀和）

int n, k, m = 0;
int a[N];
int res = 0;
int ans = 0;
int pre[N];
int back[N];
int b[N], c[N];

void check(int x){
    //int rr = m - x;
    int s1 = b[x];
    int s2 = c[m -x];
    //cout << "s1 " << s1 << " s2 " << s2 << endl;

    //int ss1 = pre[x], ss2 = back[m - x];
    //cout << "ss1 " << ss1 << " ss2 " << ss2 << endl;

    int sum = s1 + s2;
    //cout << "sum " << sum << endl;

    res = max(res, sum);
}

signed main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        //pre[i] = pre[i - 1] + a[i];
        b[i] = b[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        b[i] = max(b[i], b[i - 1]);
    }
    int idx = 1;
    for(int i = n; i >=1; i--){
        //back[idx] = back[idx - 1] + a[i];
        c[idx] = c[idx - 1] + a[i];
        idx++;
    }
    for(int i = 1; i <= n; i++){
        c[i] = max(c[i], c[i - 1]);
    }

    // k++;
    // m = (sqrt(1 + 8 * k) -1) / 2;
    // m += 1;//摸了m张牌

    while(k >= m){
        k = k - m + 1;
        m++;
        if(m >= n) break;
    }
    m = min(m, n);
    //cout << "m " << m << endl;

    for(int i = 0; i <= m; i++){
        check(i);
    }

    cout << res << endl;


    return 0;
}