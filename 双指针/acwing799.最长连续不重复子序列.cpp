#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
int s[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = 0;
    for(int i = 0, j = 0; i < n; i++){
        s[a[i]]++;
        while(s[a[i]] > 1){
            s[a[j]]--;
            j++;
        }

        res = max(res, i - j + 1);
    }
    //改2
    cout << res << endl;

    return 0;
}