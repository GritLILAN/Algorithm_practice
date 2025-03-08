#include<bits/stdc++.h>
using namespace std;

void dfs(string pre, string mid){
    if(pre.size() < 1) return;
    int m = mid.find(pre[0]);
    dfs(pre.substr(1, m), mid.substr(0, m));
    dfs(pre.substr(m + 1, pre.size() - m - 1), mid.substr(m + 1, mid.size() - m - 1));
    cout << pre[0];
}


int main(){
    string pre, mid;
    cin >> mid >> pre;

    dfs(pre, mid);


    return 0;
}