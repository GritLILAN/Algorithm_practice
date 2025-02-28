#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
//排序后转换成acwing数的范围那道题
//第一遍做没考虑到重复数对，只用了一次二分，显然是逻辑错误的
int n, x;
int a[N];

signed main(){
    cin >> n >> x;
    for(int i =  0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    int res = 0;

    //i小，mid大
    for(int i = 0; i < n; i++){
        int B = a[i];
        int l = lower_bound(a + i, a + n, B + x) - a;
        if(a[l] != B + x) continue;
        int r = upper_bound(a + i, a + n, B + x) - a;
        res += r - l;
    }

    cout << res << endl;

    return 0;
}