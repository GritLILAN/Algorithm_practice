#include <bits/stdc++.h>
using namespace std;

struct Result {
    int cuts;
    int remain;
};

int compute_cuts(int mid, int root, const vector<vector<int>>& children) {
    int n = children.size() - 1;
    vector<Result> res(n + 1);
    
    stack<int> stk;
    stk.push(root);
    stack<int> post_order;
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        post_order.push(u);
        for (int v : children[u]) {
            stk.push(v);
        }
    }
    
    stack<int> processing_order;
    while (!post_order.empty()) {
        processing_order.push(post_order.top());
        post_order.pop();
    }
    
    while (!processing_order.empty()) {
        int u = processing_order.top();
        processing_order.pop();
        int sum_remain = 1; // 当前节点自身
        int total_cuts = 0;
        for (int v : children[u]) {
            total_cuts += res[v].cuts;
            sum_remain += res[v].remain;
        }
        if (sum_remain > mid) {
            res[u].cuts = total_cuts + 1;
            res[u].remain = 0;
        } else {
            res[u].cuts = total_cuts;
            res[u].remain = sum_remain;
        }
    }
    return res[root].cuts;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (k >= n) {
        cout << 0 << '\n';
        return 0;
    }
    if (k == 0) {
        cout << n << '\n';
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 1;
    vector<vector<int>> children(n + 1);
    function<void(int, int)> build_tree = [&](int u, int parent) {
        for (int v : adj[u]) {
            if (v != parent) {
                children[u].push_back(v);
                build_tree(v, u);
            }
        }
    };
    build_tree(root, -1);

    int left = 1, right = n;
    int ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cuts = compute_cuts(mid, root, children);
        if (cuts <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
