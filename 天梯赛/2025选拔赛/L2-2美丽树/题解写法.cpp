#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;

int n, c;
int a, b;
vector<int> eg[N];
int vis[N];
int num1 = 0, root;
int ans = 0;


void dfs(ll u,ll f){
	for(int v : eg[u]){// 遍历与 now 相连的所有点
		if(v == f) continue;// 是父亲节点，直接跳出，保证只向深度更深的方向
		dfs(v, u);// 向子节点dfs
		vis[u] += vis[v];
    // vis 标记是否在要求的最小树中
	}
	return;
}

// 前面都有了，这里就只给主函数啦
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> c;
		if(c == 1){
			vis[i] = 1; // 黑点开始就标记
			num1++; // 统计黑点总数
			root = i; //
		}
	}
	for(int i = 1; i <= n-1; i++){
		cin >> a >> b;
		eg[a].push_back(b);
		eg[b].push_back(a);
	}
	dfs(root, 0);
	for(int i = 1; i <= n; i++) 
		ans += bool(vis[i]); // 统计黑点最小树大小
	printf("%lld\n", ans - num1);
	return 0;
    // 完结撒花~~
}