#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e3 + 10;

int n;
vector<int> vec(N);
bool st[N];
int res = 0;

bool check(int l , int r){
    int len = r - l + 1;
    for(int i = l; i <= r; i++){
        if(vec[i] > len ) return false;
    }
    return true;
}

void dfs(int u, int n){
    if(u == n + 1){
        // for(int i = 1; i < n; i++) cout << vec[i] << ' ';
        // cout << vec[n];
        // cout << endl;
        //res.push_back(vec);
        int cnt = 1;
        for(int i = 1; i <= n; i++){//左端点
            for(int j = i + 1; j <= n; j++){//右端点
                if(check(i, j)) cnt++;
            }
        }
        if(cnt == n) {
            for(int i = 1; i < n; i++) cout << vec[i] << ' ';
            cout << vec[n] << endl;
            res++;
        }
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
    for(int n = 3; n <= 5; n++){
        res = 0;
        cout << "n: " << n << endl;
        dfs(1, n);
        cout << "res: " <<  res << endl;
    }




    return 0;
}