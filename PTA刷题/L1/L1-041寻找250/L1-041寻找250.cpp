#include<bits/stdc++.h>
using namespace std;


int main(){
    int a;
    int i = 0;
    bool f = false;
    while(cin >> a){
        i++;
        //cout << a << endl;
        if(a == 250 && !f) {
            f = true;
            cout << i << endl;
        } 
    }



    return 0;
}