#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, m;
bool st[N];
bool vt[N];
vector<int> res;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int id; cin >> id;
            if(k > 1) vt[id] = true;
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int q; cin >> q;
        if(st[q]) continue;
        st[q] = true;

        if(!vt[q]) res.push_back(q);

    }

    if(!res.size()) cout << "No one is handsome" << endl;

    else{
        for(int i = 0; i < res.size() - 1; i++){
            cout << setw(5) << setfill('0') << res[i] << ' ';
        }
        cout << setw(5) << setfill('0') << res[res.size() - 1] << endl;
    }


    return 0;
}