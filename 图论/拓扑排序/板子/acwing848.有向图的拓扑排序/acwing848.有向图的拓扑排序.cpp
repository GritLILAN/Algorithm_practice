#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
vector<int> res;

void add(int a, int b){
    e[idx] =  b; ne[idx] = h[a]; h[a] = idx++;
}

void topsort(){
    queue<int> q;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == 0) {
            q.push(i); cnt ++;
            res.push_back(i);
        }
    }

    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            d[j] --;
            if(d[j] == 0){
                cnt ++;
                q.push(j);
                res.push_back(j);
            }
        }
    }

    if(cnt != n){
        cout << -1 << endl; return;
    }
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
}


int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    topsort();
    


    return 0;
}