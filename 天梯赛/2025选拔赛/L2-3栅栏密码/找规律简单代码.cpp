#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int h;
string s;
char ans[15][N];

void sovle(){
    int len = s.size();
    int n = 2 * h - 2;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < len; j++){
            ans[i][j] = '.';
        }
    }

    int j = 0;
    for(int i = 0; i < len; i += n){
        ans[0][i] = s[j]; j++;
    }
    for(int k = 1; k < h - 1; k++){
        for(int i = 0; i < len; i += n){
            if(i + k < len){
                ans[k][i + k] = s[j]; j++;
            }
            if(i + n - k < len){
                ans[k][i + n - k] = s[j]; j++;
            }
        }
    }
    for(int i = 0; i < len; i += n){
        ans[h - 1][i + h - 1] = s[j]; j++;
    }

    for(int i = 0; i < len; i++){
        for(int j = 0; j < h; j++){
            if(ans[j][i] != '.') s[i] = ans[j][i];
        }
    }

    cout << s << endl;
}

int main(){
    cin >> h; cin >> s;
    sovle();
    return 0;
}