#include<bits/stdc++.h>
using namespace std;

map<char, string> mp;

void init(){
    mp.insert({'0', "ling"});
    mp.insert({'1', "yi"});
    mp.insert({'2', "er"});
    mp.insert({'3', "san"});
    mp.insert({'4', "si"});
    mp.insert({'5', "wu"});
    mp.insert({'6', "liu"});
    mp.insert({'7', "qi"});
    mp.insert({'8', "ba"});
    mp.insert({'9', "jiu"});
}

int main(){
    init();

    string n;
    cin >> n;


    for(int i = 0; i < n.size(); i++){
        if(n[i] == '-') cout << "fu ";
        else if(i == n.size() - 1) cout << mp[n[i]];
        else cout << mp[n[i]] << ' ';
    }



    return 0;
}