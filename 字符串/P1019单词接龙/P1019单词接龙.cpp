#include<bits/stdc++.h>
using namespace std;
const int N = 25;

int n;
string s[N];
int st[N];
char ch;
int res = 0;

void dfs(string tmp){
    res = max(res, (int)tmp.size());


    for(int i = 0; i < n; i++){
        if(st[i] >= 2) continue;
        for(int j = 1; j < min(tmp.size(), s[i].size()); j++){
            if(tmp.substr(tmp.size() - j) == s[i].substr(0, j)){
                st[i]++;
                dfs(tmp + s[i].substr(j));
                st[i]--;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> s[i];
    }
    cin >> ch;
    
    for(int i = 0; i < n; i++){
        if(s[i][0] == ch){
            st[i]++;
            dfs(s[i]);
            st[i]--;
        } 
    }

    cout << res << endl;


    return 0;
}