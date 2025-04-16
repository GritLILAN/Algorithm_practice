#include<bits/stdc++.h>
using namespace std;



int main(){
    for(int i = 1; i <= 2025; i++){
        cout << i << ' ';
        cout << fixed << setprecision(10) << double(sqrt(i * i + 2025)) << endl;
    }
    

    return 0;
}