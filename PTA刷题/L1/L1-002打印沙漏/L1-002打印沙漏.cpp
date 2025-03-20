#include<bits/stdc++.h>
using namespace std;

int res = 0;

int main(){
    int n;
    char c;
    cin >> n;
    cin >> c;

    int num = 1;
    int sum = n;
    while(1){
        if(num == 1) sum -= num;
        else sum -= 2 * num;

        if(sum < 0){
            res = sum + 2 * num;
            break;
        }
        if(sum == 0){
            res = 0;
            break;
        }
        num += 2;
    }
    if(num != 1) num -= 2;



    for(int i = 1; i <= num; i++){
        if(i <= num / 2){
            for(int j = 1; j <= i - 1; j++) cout << ' ';
            for(int j = 1; j <= num - (i - 1) * 2; j++) cout << c;
            cout << endl;
        }
        else{
            for(int j = 1; j <= num - i; j++) cout << ' ';
            for(int j = 1; j <= num - (num - i) * 2; j++) cout << c;
            cout << endl;
        }
    }

    cout << res << endl;

    return 0;
}