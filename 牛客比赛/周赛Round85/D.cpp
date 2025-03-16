#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> pre_states(n + 1, 0);
    int pre0 = 0, pre1 = 0;
    pre_states[0] = 0;
    
    for (int k = 1; k <= n; ++k) {
        char c = s[k - 1];
        if (c == '0') {
            pre0 ^= 1;
        } else {
            pre1 ^= 1;
        }
        pre_states[k] = (pre0 << 1) | pre1;
    }
    
    int max_k[4] = {-1, -1, -1, -1};
    for (int k = 0; k <= n; ++k) {
        int state = pre_states[k];
        if (k > max_k[state]) {
            max_k[state] = k;
        }
    }
    
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == n) continue;
        int s_i = pre_states[i];
        if (max_k[s_i] >= i + 1) {
            ++count;
        }
    }
    
    double probability = static_cast<double>(count) / n;
    printf("%.10lf\n", probability);
    
    return 0;
}
