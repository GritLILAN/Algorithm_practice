#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 130;

int n;
vector<PII> a;
vector<PII> b;

bool cmp(PII a, PII b){
    return a.first > b.first;
}

int main(){
    cin >> n;
    for(int i = 1; i <= (1 << n); i++){
        int x; cin >> x;
        if(i <= (1 << n) / 2) a.push_back({x, i});
        else b.push_back({x, i});
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);


    if(a[0].first < b[0].first) cout << a[0].second << endl;
    else cout << b[0].second << endl;



    return 0;
}