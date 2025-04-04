#include<bits/stdc++.h>
using namespace std;

int cnt[4] = {0};
string str = "GPLT";

bool check(){
    for(int i = 0; i < 4; i++) if(cnt[i]) return true;

    return false;
}

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'g' || s[i] == 'G') cnt[0]++;
        if(s[i] == 'p' || s[i] == 'P') cnt[1]++;
        if(s[i] == 'l' || s[i] == 'L') cnt[2]++;
        if(s[i] == 't' || s[i] == 'T') cnt[3]++;
    }

    while(check()){
        for(int i = 0; i < 4; i++){
            if(cnt[i]){
                cout << str[i];
                cnt[i]--;
            }
        }

    }


    return 0;
}