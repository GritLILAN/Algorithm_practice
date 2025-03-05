#include<bits/stdc++.h>
using namespace std;
const int N = 110;

int n;

void get_divisors(int x){
    vector<int> a;
    for(int i = 1; i <= x / i; i++){
        if(x % i == 0){
            a.push_back(i);
            if(i != x / i) a.push_back(x / i);
        } 
    }
    sort(a.begin(),a.end());
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        get_divisors(x);

    }

    return 0;
}