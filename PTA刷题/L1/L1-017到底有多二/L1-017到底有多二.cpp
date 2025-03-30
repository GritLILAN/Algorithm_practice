#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin >> s;
    int cnt = 0;
    bool f1 = false;
    bool f2 = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '2') cnt++;
    }
    int len = s.size();
    if(s[0] == '-'){
        len--; f1 = true;
    }
    double res = double(cnt) / double(len);

    int a = s[s.size() - 1] - '0';
    if(a % 2 == 0) f2 = true;

    if(f1) res *= 1.5;
    if(f2) res *= 2;
    res *= 100;


    //printf("%.2f%\n", res);
    cout << fixed << setprecision(2);
    cout << res << '%' << endl;

    return 0;
}