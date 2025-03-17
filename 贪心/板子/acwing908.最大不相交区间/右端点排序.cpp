#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 5;

struct segment{
    int l, r;
    bool operator< (const segment &W)const{
        return r < W.r;
    }
};
int n;
int res = 0;
vector<segment> segs(n);


signed main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        segs.push_back({l, r});
    }

    sort(segs.begin(), segs.end());
    
    int ed = -2e9;
    for(auto seg : segs){
        if(seg.l > ed){
            res++;
            ed = seg.r;
        }
    }

    cout << res << endl;

    return 0;
}