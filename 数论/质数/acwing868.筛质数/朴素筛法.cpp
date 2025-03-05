#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
//朴素筛法
int n;
bool st[N];
vector<int> primes;

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes.push_back(i);
        for(int j = i; j <= n; j += i){
            st[j] = true;
        }
    }
}

int main(){
    cin >> n;

    get_primes(n);

    cout << primes.size() << endl;

    return 0;
}