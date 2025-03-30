#include<bits/stdc++.h>
using namespace std;

int h, m;
char ch;

bool check(){
    if(h == 12 && m == 0) return true;
    if(h < 12) return true;
    return false;
}

void dang(){
    int num = h % 12;
    if(m > 0 ) num++;

    for(int i = 0; i < num; i++){
        cout << "Dang";
    }
}

int main(){
    cin >> h >> ch >> m;

    if(check()){
        string hh = to_string(h);
        string mm = to_string(m);
        if(h < 10) hh = '0' + hh;
        if(m < 10) mm = '0' + mm;
        cout << "Only " << hh << ':' << mm << ".  Too early to Dang." << endl;
    }
    else{
        dang();
    }


    return 0;
}