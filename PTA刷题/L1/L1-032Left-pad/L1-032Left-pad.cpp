#include<bits/stdc++.h>
using namespace std;


int main(){
    int len;
    char ch;
    cin >> len >> ch;
    getchar();

    string s;
    getline(cin, s);

    if(s.size() > len){
        s = s.substr(s.size() - len, len);
        cout << s << endl;
        return 0;
    }

    int n = len - s.size();
    for(int i = 0; i < n; i++) cout << ch;
    cout << s << endl;


    return 0;
}