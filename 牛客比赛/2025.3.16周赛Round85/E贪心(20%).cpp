#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 5;

struct segment{
    int l, r, idx;
};

bool cmp(const segment& a, const segment& b){
    return a.l < b.l;
}

int n;
vector<segment> v;

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        v.push_back({l, r, i + 1});
    }

    sort(v.begin(), v.end(), cmp);

    int last1 = -1, last2 = -1;
    vector<int> group1, group2;
    for(int i = 0; i < n; i++){
        //cout << "last1 " << last1 << " last2 " << last2 << endl;
        if(last1 < v[i].l){
            group1.push_back(v[i].idx);
            last1 = v[i].r;
        }
        else if(last2 < v[i].l){
            group2.push_back(v[i].idx);
            last2 = v[i].r;
        }
        else{
            cout << -1 << endl; return 0;
        }
    }

    cout << group1.size() << endl;
    for(int i = 0; i < group1.size(); i++){
        cout << group1[i] << ' ';
    }

    return 0;
}