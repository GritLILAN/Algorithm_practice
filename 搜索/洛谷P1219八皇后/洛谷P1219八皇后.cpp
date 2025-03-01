#include<bits/stdc++.h>
using namespace std;
const int N = 26;

int n;
bool col[N], row[N];
bool diag[N], subdiag[N];
vector<vector<int> > res;
vector<int> tmp;

void dfs(int c){
    if(c == n + 1){
        if(tmp.size() == n) res.push_back(tmp);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!col[i] && !row[i] && !diag[c - i + n] && !subdiag[c + i]){
            col[i] = true; row[i] = true; diag[c - i + n] = true; subdiag[c + i] = true;
            tmp.push_back(i);
            dfs(c + 1);
            tmp.pop_back();
            col[i] = false; row[i] = false; diag[c - i + n] = false; subdiag[c + i] = false;
        }
    }

}

int main(){
    cin >> n;

    dfs(1);
    
    for(int i = 0; i < res.size(); i++){
        if(i >= 3) break;
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    cout << res.size() << endl;


    return 0;
}