#include<bits/stdc++.h>
using namespace std;

int res = 1;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.size(), len2 = str2.size();

    for(int i = 0; i < len1 - 1; i++){
        for(int j = len2 - 1; j > 0; j--){
            if(str1[i] == str2[j] && str1[i + 1] == str2[j - 1])
                res *= 2;
        }
    }

    cout << res << endl;

    return 0;
}