#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(stk.size() && s[i] == stk.top()){
                stk.pop();
            }
            else stk.push(s[i]);
        }

        cout << stk.size() / 2 << endl;
    }

    return 0;
}