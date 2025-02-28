#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;

int n, x;
int a[N];
map<int,int> mp;

signed main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        a[i] -= x;//假设原来的a[i]是A，那么a[i] - x就把a[i]变成了B。
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        res += mp[a[i]];
    }

    cout << res << endl;


    return 0;
}