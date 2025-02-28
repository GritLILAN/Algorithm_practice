#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, q;
int a[N];

int main(){
    cin >> n >> q;
    for(int i = 0 ; i < n; i++) cin >> a[i];

    while(q--){
        int x;
        cin >> x;
        int l = lower_bound(a, a + n, x) - a;
        if(a[l] != x){
            cout << "-1 -1" << endl; continue;
        }
        int r = upper_bound(a, a + n, x) - a;
        r -= 1;
        cout << l << ' ' << r << endl;
    }


    return 0;
}