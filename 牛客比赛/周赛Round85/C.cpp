#include<bits/stdc++.h>
using namespace std;

int cnt[2] = {0};

int main(){
    int t;
    cin >> t;
    while(t--){
        cnt[0] = 0, cnt[1] = 0;
        string s; cin >> s;
        int n = s.size();
        char last = '.';
        for(int i = 0; i < n; i++){
            if(s[i] != last){
                last = s[i];
                if(s[i] == '1') cnt[1]++;
                else cnt[0]++;
            }
        }
        int index = s[n - 1] - '0';
        cnt[index]++;

        if(cnt[0] <= 2 || cnt[1] <= 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }





    return 0;
}