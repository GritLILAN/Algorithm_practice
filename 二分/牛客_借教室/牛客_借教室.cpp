#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

//差分
int n, m;
int a[N], b[N];
int d[N], s[N], t[N];

void add(int l, int r, int c){
    b[l] += c; b[r + 1] -= c;
}

bool check(int k){
    for(int i = 1; i <= k; i++){
        add(s[i], t[i], d[i]);
    }

    for(int i = 1; i <= n; i++){
        a[i] = b[i] + a[i - 1];
        if(a[i] < 0) return true;
    }

    return false;

}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; b[i] = a[i] - a[i - 1];
    }
    for(int i = 1; i <= m; i++) cin >> d[i] >> s[i] >> t[i];

    int l = 1, r = m;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }


    cout << l << endl;

    return 0;
}