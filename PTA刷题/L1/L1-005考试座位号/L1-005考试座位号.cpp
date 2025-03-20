#include<bits/stdc++.h>
using namespace std;

struct node{
    string id;
    int num;
};

int n, m;


int main(){
    cin >> n;
    vector<node> mp(n + 1);
    for(int i = 1; i <= n; i++){
        string s;
        int index, num;
        cin >> s >> index >> num;
        mp[index].id = s;
        mp[index].num = num;
    }

    cin >> m;
    while(m--){
        int k; cin >> k;
        cout << mp[k].id << ' ' << mp[k].num << endl;
    }

    return 0;
}