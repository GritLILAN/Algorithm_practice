#include<bits/stdc++.h>
using namespace std;
//四舍五入用round实现
int n;
char ch;

int main(){

    cin >> n >> ch;
    int row =  round(double(n) / double(2));
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= n; j++){
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}