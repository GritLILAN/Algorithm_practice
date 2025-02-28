#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
int a[N];


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    long long res = 0;
    while(m--){
        int b;
        cin >> b;
        int index = upper_bound(a, a + n, b) - a;//upper和lower都可以
        //cout << "index:" << index << endl;
        if(index == 0) res += abs(a[index] - b);
        else if(index == n) res += (b - a[n - 1]);
        else res += min(abs(a[index] - b), abs(a[index - 1] - b));
    }

    cout << res << endl;


    return 0;
}