#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
int lchild[N], rchild[N];
int deep[N];
int res = 0;

void bfs(){
    queue<int> q;
    q.push(1);
    deep[1] = 1;

    while(q.size()){
        auto t = q.front();
        q.pop();
        res = max(res, deep[t]);

        int l = lchild[t], r = rchild[t];
        // cout << "current:" << t << endl;
        // cout << l << ' ' << r << endl;
        if(l != 0){
            deep[l] = deep[t] + 1; q.push(l);
        }
        if(r != 0){
            deep[r] = deep[t] + 1;q.push(r);
        }
   

    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        lchild[i] = l, rchild[i] = r;
    }

    bfs();

    cout << res << endl;

    return 0;
}
