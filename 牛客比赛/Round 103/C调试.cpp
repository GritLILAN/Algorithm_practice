#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e3 + 10;

int n;
vector<int> vec(N);
//vector<vector<int> > res;
bool st[N];
int res = 0;

bool check(int l , int r){
    cout << "l r" << endl;
    cout << l << ' ' << r << endl;
    bool f = false;
    int len = r - l + 1;
    cout << "index: " << endl;
    for(int i = l; i <= r; i++){
        cout << i << ' ';
    }
    cout << endl;
    for(int i = l; i <= r; i++){
        cout << vec[i] << ' ';
        if(vec[i] > len ) f = true;
    }
    cout << endl;
    if(f) return false;
    return true;
}

void dfs(int u, int n){
    if(u == n + 1){
        for(int i = 1; i < n; i++) cout << vec[i] << ' ';
        cout << vec[n];
        cout << endl;
        //res.push_back(vec);
        int cnt = 1;
        for(int i = 1; i <= n; i++){//左端点
            for(int j = i + 1; j <= n; j++){//右端点
                if(check(i, j)) cnt++;
            }
        }
        cout << "cnt: " << cnt << endl;
        cout << "-----------------" << endl;
        if(cnt == n) res++;
    }
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            vec[u] = i;
            st[i] = true;
            dfs(u + 1, n);
            st[i] = false;
        }       
    }
}

signed main(){
    //cin >> n;
    for(int n = 3; n <= 3; n++){
        res = 0;
        cout << "n: " << n << endl;
        dfs(1, n);
        cout << "res: " <<  res << endl;
    }




    return 0;
}