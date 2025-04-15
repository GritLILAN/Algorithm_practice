#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(!i) cout << min(5, a + 1);
        else cout << ' ' << min(5, a - 1);
    }


    return 0;
}