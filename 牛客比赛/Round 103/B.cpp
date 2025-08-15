#include<bits/stdc++.h>
using namespace std;

int n; 

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        int s;
        cin >> s;
        int cnt = 0;
        for(int i = 1; i < n; i++){
            int x; cin >> x;
            if(x != s){
                cnt++;
                s = x;
            }
        }
        if(cnt <= 2) cout << "YES" << endl;
        else cout << "NO" << endl;

    }



    return 0;
}