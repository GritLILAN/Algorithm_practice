#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 2e5; // 最大可能的 a_i + m 是 2e5

long long fact[MAX_N + 1];
long long inv_fact[MAX_N + 1];

// 快速幂计算
long long pow_mod(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

// 预处理阶乘和逆元
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAX_N] = pow_mod(fact[MAX_N], MOD - 2);
    for (int i = MAX_N - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

int main() {
    precompute();
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long result = 1;
    for (int ai : a) {
        int total = ai + m;
        // 计算组合数 C(total, m)
        long long comb = fact[total] * inv_fact[m] % MOD;
        comb = comb * inv_fact[ai] % MOD;
        result = result * comb % MOD;
    }
    cout << result << endl;
    return 0;
}
