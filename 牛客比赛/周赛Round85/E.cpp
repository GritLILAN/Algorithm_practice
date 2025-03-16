#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 5;

int n;
vector<PII> v;
int color[N];


signed main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        v.push_back(make_pair(l, r));
    }

    sort(v.begin(), v.end());

    for(int i = 2; i < n; i++){
        int l1 = v[i - 2].first, r1 = v[i - 2].second;
        int l2 = v[i].first, r2 = v[i].second;
        // cout << l1 << ' ' << r1 << endl;
        // cout << l2 << ' ' << r2 << endl;
        // cout << "-----------------" << endl;
        if(r1>= l2){
            cout << "-1" << endl; return 0;
        }
    }

    for(int i = 1; i <= n; i++){
        if(i & 1) cout << i << ' ';
    }

    return 0;
}