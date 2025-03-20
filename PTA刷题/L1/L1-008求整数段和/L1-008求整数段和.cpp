#include<bits/stdc++.h>
using namespace std;


int main(){
    int a, b;
    cin >> a >> b;
    int sum = 0;
    int cnt = 0;
    for(int i = a; i <= b;i++){
        sum += i;

        if(cnt == 5){
            cnt = 0;
            cout << endl;
        }
        cnt++;
        printf("%5d", i);
    }
    cout << endl;
    cout << "Sum = " << sum;


    return 0;
}