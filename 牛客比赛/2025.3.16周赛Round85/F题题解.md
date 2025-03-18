### 原题链接
https://ac.nowcoder.com/acm/contest/103948/F
### 题目大意
有一棵`n`个节点都是红色的树，小紫准备将`k`个节点染成紫色，使得最大连通块大小最小。
### 解题思路
$\qquad$最大值最小，很容易想到二分答案。在`[0,n]`范围内查找连通块大小的值(`mid`)。对于每个`mid`，`check`函数中计算想要达到最大连通块大小为`mid`值需要将几个节点染成紫色，假定这种情况下染紫了`use`个点，若`use <= k`则说明都不用花费`k`个点就能达到这个`mid`连通块大小。根据性质最大连通块大小越大花费的(染紫的)节点数越少，所以`use <= k`的情况下说明现在找的这个`mid`太大了，应该往小继续找，即`r = mid`。
$\qquad$二分部分说完了，接下来是`check`函数怎么具体实现，统计某个连通块数量的问题，能想到计算子树大小的方法。维护一个==`siz[i]`数组表示节点`i`的子树中有多少个与`i`联通的红色节点。==`dfs`过程中若`siz[u] > mid`，说明这个连通块已经比想要的效果大了，需要染紫`use++`，并且`siz[u] = 0`标记这个子树是一个独立的连通块，防止它上面的节点统计的时候把这个连通块也统计了。
### 代码
```cpp
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 5;

  

int n, k;

vector<int> g[N];

int siz[N];//节点i的子树中与i联通的红色节点个数

int use = 0;

  

void dfs(int u, int f, int mid){

  

    for(int v : g[u]){

        if(v == f) continue;

        dfs(v, u, mid);

        siz[u] += siz[v];

    }

    if(siz[u] > mid){

        use++;//紫色节点+1

        siz[u] = 0;//标记这个子树为独立的连通块

    }

}

  

bool check(int mid){

    use = 0;

    for(int i = 1; i <= n; i++) siz[i] = 1;

    dfs(1, 0, mid);

    return use <= k;//染紫的节点数少，说明连通块大小mid太大

}

  
  

signed main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

  

    cin >> n >> k;

    for(int i = 0; i < n - 1; i++){

        int u, v; cin >> u >> v;

        g[u].push_back(v);

        g[v].push_back(u);

    }

  

    int l = 0, r = n;

    while(l < r){

        int mid = l + r >> 1;

        if(check(mid)) r = mid;

        else l = mid + 1;

    }

  

    cout << l << endl;

  

    return 0;

}
```