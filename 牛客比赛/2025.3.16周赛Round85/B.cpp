#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
int x = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    for(int i = 0; i < n; i++){
        if(i % 2 == 0) x += a[i];
        else x -= a[i];
    }

    cout << x;

    return 0;
}