#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, k;
int a[N];
int L = 0;

int check(int x){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i] / x;
    }
    return sum;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i]; L = max(L, a[i]);
    } 


    int l = 0, r = L;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid) >= k) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;



    return 0;
}