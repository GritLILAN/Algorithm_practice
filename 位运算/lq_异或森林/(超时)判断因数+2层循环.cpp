#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;

int n;
int a[N];
int s[N];//异或前缀和
unordered_map<int,int> prime;

bool check(int x){
    //cout << x << endl;
    for(int i = 2; i * i <= x; i++){
        while(x % i == 0){
            x /= i;
            prime[i] ++;
        }
    }
    if(x > 1) prime[x]++;


    int ans = 1;
    for(auto i : prime){
        ans = ans * (i.second + 1);
    }

    //cout << "ans:" << ans << endl;

    if(ans % 2 == 0) return true;
    else return false;
}

int main()
{
    int res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; s[i] = s[i - 1] ^ a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int tmp = s[j] ^ s[i - 1];
            prime.clear();
            if(check(s[j] ^ s[i - 1])){
                res++;
                // cout << "tmp:" << tmp << endl;
                // cout << "i j:" << i << ' ' << j << endl;
                // cout << endl;
            }
        }
    }

    // int l = 2, r = 4;
    // int test = s[r] ^ s[l - 1] ;
    // cout << test << endl;

    // cout << check(test) << endl;

    // cout << check(4) << endl;

    cout << res << endl;
  
  return 0;
}