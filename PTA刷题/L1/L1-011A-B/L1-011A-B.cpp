#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);

    for(int i = 0; i < a.size(); i++){
        bool f = false;
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]){
                f = true; break;
            } 
        }
        if(!f) cout << a[i];
    }

    return 0;
}