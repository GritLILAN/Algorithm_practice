#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i] != s[i + 1]) cnt++;
        }

        if(n < 4){
            cout << 0 << endl;
            continue;
        }

        if(cnt >= 3) cout << 0 << endl;
        else if(cnt == 2){
            if(s == "0110" || s == "1001") cout << 2 << endl;
            else cout << 1 << endl;
        }
        else if(cnt == 1){
            if(s == "1100" || s == "0011") cout << 2 << endl;
            else cout << 1 << endl;
        }
        else cout << 2 << endl;
    

    }




    return 0;
}