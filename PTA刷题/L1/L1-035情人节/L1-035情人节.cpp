#include<bits/stdc++.h>
using namespace std;

vector<string> s;

int main(){
    while(1){
        string str; cin >> str;
        if(str == ".")break;
        if(s.size() <= 14) s.push_back(str);
    }

    int n = s.size();
    if(n < 2) cout << "Momo... No one is for you ..." << endl;
    else if(n < 14) cout << s[1] << " is the only one for you..." << endl;
    else cout << s[1] << " and " << s[13] << " are inviting you to dinner..." << endl;

    return 0;
}