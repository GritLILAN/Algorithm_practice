#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod = 1e9 + 7;

unordered_map<int,int> primes;

signed main(){
    int m; cin >> m;
    while(m--){
        int n; cin >> n;
        for(int i = 2; i <= n / i; i++){
            if(n % i == 0){
                while(n % i == 0){
                    primes[i]++;
                    n /= i;
                }
            }
        }
        if(n > 1) primes[n]++;
    }

    int res = 1;
    for(auto t : primes){
        res = res * (t.second + 1) % mod;
    }

    cout << res << endl;

    return 0;
}