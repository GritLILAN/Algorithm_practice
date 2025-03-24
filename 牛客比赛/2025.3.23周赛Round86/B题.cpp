#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e5 + 5;

int n, k;
int a[N];

signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > 0) sum += a[i];
        }
        cout << sum << endl;
    }
    

    return 0;
}