### 原题链接
https://ac.nowcoder.com/acm/contest/102896
### 题目大意
一共`n`个格子（一维），每个格子上有一个数字，可正可负，踩到某个格子会获得（负数失去）上面数量的金币。每次移动可选择走的步数为区间`[1,6]`，恰好移动`k`次后，获得金币数量最多是多少。
### 解题思路
明显是DP题目，我们开一个二维dp数组`dp[i][j]`，表示在抵达第`i`格时总共移动了`j`次的状态。状态转移考虑上一步在哪，可能有6种情况，因为一次可以选择的步数有6种。可得状态转移方程：
$$dp[i][j] = max\{dp[i][j], dp[i-dc][j-1]+a[i]\}$$
其中`dc`是骰子可能的值`[1,6]`。
### 代码
```cpp
#include<bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;

const int N = 1e4 + 5;

const int INF = -1145141919810;

  

int n,k;

int a[N];

int dp[N][1005];

int res = INF;

  

signed main(){

    cin >> n >> k;

    memset(dp, INF, sizeof dp);

    for(int i = 1; i <= n; i++){

        cin >> a[i];

    }

    dp[0][0] = 0;

  

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= min(i, k); j++){

            for(int p = max((ll)0, i - 6); p < i; p++){

                dp[i][j] = max(dp[i][j], dp[p][j - 1] + a[i]);

            }

        }

        res = max(res, dp[i][k]);

    }

  

    cout << res << endl;

  
  

    return 0;

}
```