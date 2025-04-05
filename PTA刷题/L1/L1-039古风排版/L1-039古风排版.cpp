#include<bits/stdc++.h>
using namespace std;

int n;
string s;
string res[110];

int main(){
    cin >> n;
    getchar();
    getline(cin, s);

    for(int i = 0; i < s.size(); i++){
        int idx = i % n;
        res[idx] = s[i] + res[idx];
    }
    int len = res[0].size();

    for(int i = 0; i < n; i++){
        if(res[i].size() < len) cout << ' ';
        cout << res[i] << endl;
    }


    return 0;
}