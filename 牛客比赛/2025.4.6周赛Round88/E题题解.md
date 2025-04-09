### 题目大意
表世界和里世界都有一个长度为n的数组，`a[i]`和`b[i]`分别表示表里世界第`i`号点有几个金币。
玩家从表世界1号点出发，获取该点金币，线性顺序移动，如果持有金币大于k，则可以穿越到另一个世界拾取其下一个点的金币。
求走到第n号点时最大金币数。
### 解题思路
一眼dp，`dp[i][0]`表示第`i`个点选择拾取表世界金币时，当前的最大金币数，`dp[i][1]`表示第`i`个点选择拾取里世界金币时，当前的最大金币数。
状态转移方程：
$$
dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i - 1][!j] - k)
$$
注意：状态转移之前要先判断，若选择传送的话之前的金币余额是否足够。如果`dp[i - 1][!j] < k`的话，说明这个情况不可能发生，直接给`dp[i - 1][!j]`赋值负无穷。
### 代码
```cpp
#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 5;

//不可能路径设置成负无穷

  

int n, k;

int a[N][2];

int dp[N][2];

  

signed main(){

    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i][0];

    for(int i = 1; i <= n; i++) cin >> a[i][1];

  

    dp[1][0] = a[1][0];

    dp[1][1] = -1e18;

    for(int i = 2; i <=n; i++){

        for(int j = 0; j < 2; j++){

            if(dp[i - 1][!j] < k) dp[i - 1][!j] = -1e18;

            //dp[i][j] = a[i][j] + max(dp[i - 1][j], (int)(dp[i - 1][!j] >= k ? dp[i - 1][!j] - k : -1e18));

            dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][!j] - k);

        }

    }

  

    cout << max(dp[n][0], dp[n][1]) << endl;

  

    return 0;

}
```
