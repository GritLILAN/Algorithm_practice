#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, m;
bool st[N];
vector<int> res;

int main(){
    cin >> n;
    vector<set<int>> s(n);
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int id; cin >> id;
            s[i].insert(id);
        }
    }

    cin >> m;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int q; cin >> q;
        if(st[q]) continue;
        st[q] = true;
        bool f = true;
        for(int j = 0; j < n; j++){
            if(s[j].count(q) && s[j].size() != 1){
                f = false;
            }
        }
        if(f){
            //cout << q << ' ';
            res.push_back(q);
            cnt++;
        }
    }

    if(!cnt) cout << "No one is handsome" << endl;

    else{
        for(int i = 0; i < res.size() - 1; i++){
            cout << res[i] << ' ';
        }
        cout << res[res.size() - 1] << endl;
    }


    return 0;
}