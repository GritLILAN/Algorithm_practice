#include<bits/stdc++.h>
using namespace std;

string n;
int cnt[15];

int main(){

    cin >> n;
    for(int i = 0; i < n.size(); i++){
        cnt[n[i] - '0']++;
    }

    for(int i = 0; i <= 9; i++){
        if(cnt[i]) cout << i << ":" << cnt[i] << endl;
    }


    return 0;
}