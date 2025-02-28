#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;

int n, x;
int a[N];

signed main(){
    cin >> n >> x;
    for(int i =  0; i < n; i++)cin >> a[i];
    
    sort(a, a + n);
    int res = 0;
    for(int i = 0; i < n; i++){
        int B = a[i];
        
        int l = i, r = n - 1;
        while(l < r){
            int mid = l + r + 1>> 1;
            if(B + x >= a[mid]) l = mid;
            else r = mid - 1;
        }
        int rr = l;
        if(a[rr] != B + x) continue;

        l = i, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(B + x <= a[mid]) r = mid;
            else l = mid + 1;
        }
        int ll = l;
        
        // cout << i << endl;
        // cout << ll << ' ' << rr << endl;

        res += rr - ll + 1;
    }

    cout << res << endl;

    return 0;
}