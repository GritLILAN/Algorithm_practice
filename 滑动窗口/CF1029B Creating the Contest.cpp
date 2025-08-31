#include<bits/stdc++.h>
using namespace std;

int n;

queue<int> q;
int res = 0;

int main(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        q.push(a[i]);
        while(q.size() && q.front() * 2  < a[i]){
            q.pop();
        }
        res = max(res, (int)q.size());
    }

    cout << res << endl;

    return 0;
}