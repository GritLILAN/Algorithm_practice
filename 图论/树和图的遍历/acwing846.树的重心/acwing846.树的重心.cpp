#include<bits/stdc++.h>
using namespace std;
const int  N = 1e5 + 5, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N;

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

//返回以u为根的子树中的节点个数，包括u
int dfs(int u){
    st[u] = true;
    //sum是节点u下面的节点数（包括u）
    //res是删掉u后，最大连通子图的节点数
    int sum = 1, res = 0;
    
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);//判断节点u子树之上的所有节点是否是最大联通块
    ans = min(ans, res);
    return sum;
}


int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        add(a,b); add(b,a);
    }

    dfs(1);//由于是无向图（双向），可以任意选择一个节点开始遍历

    cout << ans << endl;

    return 0;
}