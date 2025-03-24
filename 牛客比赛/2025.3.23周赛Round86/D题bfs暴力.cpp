#include<bits/stdc++.h>
using namespace std;
//vec是集合，cnt维护当前是第几次操作

int main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        queue<pair<pair<int, int>, int> > q;
        vector<int> vec{x, y};

        q.push({{x, y}, 0});
        while(q.size()){
            auto [u, cnt] = q.front();
            auto &[x, y] = u;
            q.pop();
            if((x & y) == 0 || (x | y) == 0 || (x ^ y) == 0){
                cout << cnt + 1<< endl; break;
            }
            int g = __gcd(x, y);
            int a[4] = {x & y, x | y, x ^ y, g};
            for(auto num : vec){
                for(int i = 0; i < 4; i++){
                    q.push({{num, a[i]}, cnt + 1});
                }
            }
            for(int i = 0; i < 4; i++){
                vec.push_back(a[i]);
            }
        }

    }

    return 0;
}