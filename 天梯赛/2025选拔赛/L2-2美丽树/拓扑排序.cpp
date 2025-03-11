#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
int h[N], e[2 * N], ne[2 * N], idx;
bool st[N];
int num = 0;//白点数量
queue<int> q;
int d[N];//度数


void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int topo(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == 1 && !a[i]) {
            q.push(i); a[i] = 1;
        }
    }
    while(q.size()){
        auto t = q.front();
        q.pop();
        d[t]--;
        cnt++;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(d[j] == 1 && a[j] == 0) {
                //如果是度数为1的白点，入队
                //度数为0的白点已经处理过了，不能入队
                q.push(j);
            }
        }
    }
    return cnt;
}


int main(){
    memset(h, -1, sizeof h);
    cin >> n;
    int root = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!a[i]) num++;
    }
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        add(a,b); add(b,a);
        d[a]++; d[b]++;
    }

    //特判，有一个测试点全是白点
    if(num == n){//如果全是白点，那么操作次数为0
        cout << 0 << endl; return 0;
    }

    int res = num - topo();
    cout << res << endl;

    return 0;
}