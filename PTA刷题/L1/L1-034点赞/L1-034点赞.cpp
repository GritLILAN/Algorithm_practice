#include<bits/stdc++.h>
using namespace std;

int n;
map<int, int> mp;
int res = 0, num = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int a; cin >> a;
            mp[a]++;
        }
    }
    for(auto u : mp){
        int id = u.first, cnt = u.second;
        if(num < cnt){
            res = id; num = cnt;
        }
        else if(num == cnt){
            res = max(res, id);
        }
    }

    cout << res << ' ' << num << endl;

    return 0;
}