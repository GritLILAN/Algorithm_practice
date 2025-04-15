#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n, k;
deque<int> q;
int res = 0;
int ans = 0;


signed main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        q.push_back(a);
    }

    int cnt = 0;
    while(k >= cnt && q.size()){
        //cout << cnt << endl;
        int a = q.front(), b = q.back();
        if(a >= b){
            res += a; q.pop_front();
        }
        else{
            res += b; q.pop_back();
        }

        ans = max(ans, res);
        //cout << "res" << res << endl;
        k++;
        k -= cnt;
        cnt++;
    }

    cout << ans << endl;

    return 0;
}