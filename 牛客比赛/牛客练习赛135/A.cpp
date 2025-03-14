#include<bits/stdc++.h>
using namespace std;

int x, y, n;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> x >> y >> n;
        if(n < x){
            cout << n << endl;
        }

        else cout << x - 1 << endl;

    }

    return 0;
}