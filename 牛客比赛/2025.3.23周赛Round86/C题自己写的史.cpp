#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int pre[N];


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        s = '.' + s;
        int pre0 = 0;
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == '0') pre0 ^= 1;
            pre[i] = pre0;
        }
        int last = 0;
        for(int i = 1; i <= n; i++){
            if(i == 1){
                if(s[i] == '0' && s[i + 1] == '1') res++;
                continue;
            }
            if(i == n){
                if(s[i] == '0' && s[i - 1] == '1') res++;
                continue;
            }
            if(s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1'){
                res++;
                if(pre[last] == pre[i]) res -= 2; 
                last = i;
            }
        }
        if(n & 1){
            if(res & 1) res--;
        }
        cout << res << endl;
    }


    return 0;
}