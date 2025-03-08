#include<bits/stdc++.h>
using namespace std;
const int N = 200;

int n;
int lchild[N], rchild[N];

void dfs(int u){
    if(u == int('*')){
        return;
    }
    cout << (char)u;
    dfs(lchild[u]);
    dfs(rchild[u]);
}

int main(){
    cin >> n;
    int root;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        if(i == 1) root = s[0];
        lchild[s[0]] = s[1];
        rchild[s[0]] = s[2];
    }

    dfs(root);



    return 0;
}