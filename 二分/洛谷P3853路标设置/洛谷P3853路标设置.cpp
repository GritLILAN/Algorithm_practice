#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int L, n, k;
int a[N];
int dis[N];

bool check(int x){
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(dis[i] > x) cnt += (dis[i] - 1) / x;
    }
    if(cnt <= k) return true;
    else return false;
}

int main(){
    cin >> L >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];  
    for(int i = 1; i < n; i++) {
        dis[i] = a[i] - a[i - 1];
    }

    int l = 1, r = L;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;


    return 0;
}