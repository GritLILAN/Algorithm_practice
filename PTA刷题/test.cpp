#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "hello world";
    if(s.find("hello") != string::npos){  // 修改处：添加string::限定
        cout << "yes" << endl;
    }

    int d = 12345;
    string dd = to_string(d);
    cout << dd << endl;

    string num = "0123";
    int numd = stoi(num);
    cout << numd << endl;

    return 0;
}