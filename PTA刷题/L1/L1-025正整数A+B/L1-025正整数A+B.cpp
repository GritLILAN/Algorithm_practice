#include<bits/stdc++.h>
using namespace std;

bool check(string a){
    if(a[0] == '-') return false;
    for(int i = 0; i < a.size(); i++){
        if(a[i] < '0' || a[i] > '9') return false;
    }

    return true;
}

int main(){
    string a, b;
    cin >> a >> b;
    string t;
    while(cin >> t){
        b += t;
    }

    bool f1 = true;
    bool f2 = true;
    int sum = 0;
    if(check(a)){
        int aa = stoi(a);
        sum += aa;
        if(aa < 1 || aa > 1000) f1 = false;
    }
    else f1 = false;
    if(check(b)){
        int bb = stoi(b);
        sum += bb;
        if(bb < 1 || bb > 1000) f2 = false;
    }
    else f2 = false;

    if(f1 && f2){
        cout << a << " + " << b << " = " << sum << endl;
    }
    else{
        if(f1) cout << a;
        else cout << '?';
        cout << " + ";

        if(f2) cout << b;
        else cout << '?';
        cout << " = ?" << endl;
    }



    return 0;
}