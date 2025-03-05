#include<bits/stdc++.h>
using namespace std;
const int N  = 1e6 + 5;
//线性筛
int n;
bool st[N];
vector<int> primes;

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes.push_back(i);
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    cin >> n;

    get_primes(n);

    cout << primes.size() << endl;


    return 0;
}