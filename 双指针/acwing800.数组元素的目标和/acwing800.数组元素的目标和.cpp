#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n,m,x;
int a[N], b[N];


int main(){
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int i,j;
    for(i = 0, j = m - 1; i < n; i++){
        while(j >= 0 && a[i] + b[j] > x) j--;
        if(a[i] + b[j] == x) break;
    }

    cout << i << ' ' << j << endl;

    return 0;
}
