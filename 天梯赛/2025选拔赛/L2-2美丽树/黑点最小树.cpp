#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
int h[N], e[2 * N], ne[2 * N], idx;
bool st[N];
int sz[N];
int num = 0;
int res = 0;


void add(int a, int b){
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u){
  st[u] = true;

  for(int i = h[u]; i != -1; i = ne[i]){
    int j = e[i];
    if(st[j]) continue;
    dfs(j);
    sz[u] += sz[j];//自身（要么0，要么1）加上子树的size
  }
  return;
}


int main(){
    memset(h, -1, sizeof h);
    cin >> n;
    int root = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1) {
            root = i;
            num++;//黑点数量
            sz[i] = 1;//初始化标记一下黑点
        }
    }
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        add(a,b); add(b,a);//不确定根节点，双向边建树
    }

    dfs(root);

    for(int i = 1; i <= n; i++){
        res += bool(sz[i]);//统计最小树大小
    }

    res -= num;//最小树大小减去黑点数量
    
    cout << res << endl;

    return 0;
}