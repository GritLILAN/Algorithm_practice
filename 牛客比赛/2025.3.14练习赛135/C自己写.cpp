#include<iostream>
#include<string>
#define int long long 
using namespace std;
const int N = 1e5 + 5;

int n, q;
string s;
string perm;
int cnt[26][26];//cnt[a][b]表示字母a在字母b前出现的次数
int count[26] = {0};//记录字符出现次数临时数组
int rk[26];

signed main(){
    cin >> n >> q;
    cin >> s;
    for(int i = 0; i < n; i++){
        int c = s[i] - 'a';
        for(int b = 0; b < 26; b++){
            cnt[b][c] += count[b];
        }
        count[c]++;
    }

    while(q--){
        int res = 0;
        cin >> perm;
        for(int i = 0; i < 26; i++){
            int c = perm[i] - 'a';
            rk[c] = i;
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(i != j && rk[i] > rk[j])
                    res += cnt[i][j];
            }
        }
        cout << res << endl;
    }



    return 0;
}