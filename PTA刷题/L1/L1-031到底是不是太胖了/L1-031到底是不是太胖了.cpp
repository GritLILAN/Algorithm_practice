#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int h, w;
        cin >> h >> w;

        double std_w = (h - 100) * 0.9 * 2;
        if(abs(w - std_w) < 0.1 * std_w) cout << "You are wan mei!" << endl;
        else{
            if(w > std_w) cout << "You are tai pang le!" << endl;
            else cout << "You are tai shou le!" << endl;
        }

    }

    return 0;
}