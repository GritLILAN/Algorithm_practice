#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int sum = 0;
    int prev = 0;  // 用于记录前一个有效数值
    for (int num : a) {
        if (num > n) continue;    // 跳过超过牌数量的数值
        if (num != prev) {        // 去重处理
            sum += num;
            prev = num;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}