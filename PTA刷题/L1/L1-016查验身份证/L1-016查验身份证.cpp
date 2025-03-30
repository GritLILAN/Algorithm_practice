#include<bits/stdc++.h>
using namespace std;

int n;
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
map<int, char> mp = {
    {0, '1'},
    {1, '0'},
    {2, 'X'},
    {3, '9'},
    {4, '8'},
    {5, '7'},
    {6, '6'},
    {7, '5'},
    {8, '4'},
    {9, '3'},
    {10, '2'}
};

int main(){
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int sum = 0;
        bool f = true;
        for(int j = 0; j < 17; j++){
            if(s[j] < '0' || s[j] > '9'){
                f = false; break;
            }
            int a = s[j] - '0';
            sum = (sum + a * weight[j]) % 11;
        }
        if(mp[sum] != s[17]) f = false;

        if(!f) {
            cout << s << endl; cnt++;
        }
    }

    if(!cnt) cout << "All passed" << endl;


    return 0;
}