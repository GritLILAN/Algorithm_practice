#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int flag = 0;
        for(int i = 0; i < n; i++){
            if(flag) cout << 1 << ' ';
            else cout << 2 << ' ';

            flag = !flag;
        }
        cout << endl;
    }



    return 0;
}