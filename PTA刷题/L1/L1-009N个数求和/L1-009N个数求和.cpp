#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 110;

struct frac{
    int a, b;
};
int n;
frac v[N];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int cal(string s){
    int num = 0;
    bool neg = false;
    if(s[0] == '-') neg = true;
    for(int i = 0; i < s.size(); i++){
        int u = s[i] - '0';
        if(s[i] != '-') num += u;
        if(i != s.size() - 1) num *= 10;
    }
    if(neg) return -num;
    return num;
}

signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '/') idx = i;
        }
        string sa = s.substr(0, idx);
        string sb = s.substr(idx + 1, s.size() - idx - 1);
        //cout << sa << ' ' << sb << endl;
        int a = cal(sa);
        int b = cal(sb);
        //cout << a << ' ' << b << endl;
        v[i].a = a; v[i].b = b;
    }

    //计算分母最小公倍数
    int lcm;
    int a = v[1].b;
    for(int i = 2; i <= n; i++){
        int b = v[i].b;
        int gcdd = gcd(a, b);
        lcm = a * b / gcd(a, b);
        a = lcm;
    }

    //计算通分后分子的和
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int mul = lcm / v[i].b;
        sum += mul * v[i].a;
    }

    int res_gcd = gcd(sum, lcm);
    
    if(!sum){
        cout << 0 << endl; return 0;
    } 
    sum /= res_gcd; lcm /= res_gcd;
    
    if(sum / lcm == 0){
        cout << sum << '/' << lcm << endl;
    }
    else{
        int num = sum / lcm;
        sum = sum % lcm;
        cout << num ;
        if(sum != 0) cout << ' ' <<  sum << '/' << lcm << endl;
    }


    // if(sum / lcm) cout << sum / lcm;
    // if(sum / lcm && sum % lcm != 0) cout << " ";
    // if(sum % lcm != 0){
    //     sum = sum % lcm;
    //     cout << sum << '/' << lcm << endl;
    // }
    // if(!sum){
    //     cout << 0 << endl;
    // }



    return 0;
}