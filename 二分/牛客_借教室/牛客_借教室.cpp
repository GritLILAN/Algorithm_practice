#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

//差分
int n, m;
int a[N], b[N];
int d[N], s[N], t[N];

void add(int l, int r, int c){
    b[l] += c; b[r + 1] -= c;
}

bool check(int k){
    //由于在check里面进行了增减操作，之后没有恢复数组
    //所以我们用b[]数组作为临时数组，只在check里生效
    for(int i = 1; i <= n; i++) b[i] = a[i];
    for(int i = 1; i <= k; i++){
        add(s[i], t[i], -d[i]);
    }

    int sum = 0;
    for(int i = 1; i <= n; i++){
        // b[i] = b[i] + b[i - 1];
        sum += b[i];
        if(sum < 0) return true;
    }

    return false;

}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
        //a[i] = a[i] - a[i - 1];
        //用上面这一行将a[]转换成自己的差分数组显然是不行的
    }
    for(int i = 1; i <= m; i++) cin >> d[i] >> s[i] >> t[i];

    //注意：反向倒着处理差分数组(因为是自身赋值)
    for(int i = n; i >0; i--) a[i] -= a[i - 1];

    int l = 1, r = m;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    if(check(l)) cout << l << endl;
    else cout << 0 << endl;

    return 0;
}