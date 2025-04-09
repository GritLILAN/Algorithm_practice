#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 2e5 + 5;

int n;
int a[N];
int sum;
queue<PII> q;

bool check(){

}


int main(){
    cin >> n;
    sum = n * 3;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i]){
            sum -= a[i];
            q.push({a[i], i});
        }
    }

    if(!check()){
        cout << -1 << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }


    return 0;
}