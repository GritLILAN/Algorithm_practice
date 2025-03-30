#include<bits/stdc++.h>
using namespace std;

int a[3];
int main(){
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a, a + 3);

    cout << a[0];
    for(int i = 1; i < 3; i++){
        cout << "->" << a[i];
    }

    return 0;
}