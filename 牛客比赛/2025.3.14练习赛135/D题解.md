### 原题链接
https://ac.nowcoder.com/acm/contest/103151
### 题目大意
一共有`n`种糖果，每种糖果有`a[i]`颗，班里有`m`名学生，问一共有多少种发糖果方案(某学生可以不被发到，可以有剩余糖果)。答案对$10^9+7$取模后输出。
### 解题思路
首先这是一个组合数问题，数据范围$1 \leq n,m \leq 10^5$，所以用预处理阶乘的方式计算组合数。
其次，这是一个==隔板法==的模型，先说明一下隔板法。
隔板法用来处理`n`个相同的小球放进`m`个不同盒子的经典问题。
传统隔板法的3个条件：
（1）`n`个元素必须相同
（2）`m`个组(盒子)必须是互异的
（3）每组至少有`1`个元素

普通隔板法举例：
有10个球，要放进3个盒子里，可以用2个板子将这些球分成3个部分。而10个球就意味着有9个间隙，所以这道题被简化为从9个间隙中选2个间隙去放置板子。即：
$$C_{n - 1}^{m - 1}$$
对于允许有空盒子存在的情况，叫做==添元素隔板法==。
对于这种情况，我们将每个盒子都提前放进`1`个球进去，这样每个盒子都保底有`1`个球，就转化成传统隔板法了。公式：
$$C_{n+ m -1}^{m - 1}$$
接下来就是这个题的思路。
对于某一种糖果的发放方案(假设这种糖果有`n`个)，由于糖果不必全部发完，所以我们假设剩下的糖果发给虚拟的第`m + 1`个人，那么问题就变成了将`n`个糖果放在`m + 1`个盒子里的模型,也就是$C_{n + m + 1 -1}^{m + 1 - 1}$。最后将每种糖果的方案数相乘即可得到最终答案。
### 代码
```cpp
#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 5;

const int mod = 1e9 + 7;

  

int n,m;

int v[N];

int fact[N], infact[N];

int res = 1;

  

int qpow(int a, int b, int p){

    int ans = 1;

    while(b){

        if(b & 1) ans = ans * a % mod;

        b >>= 1;

        a = a * a % mod;

    }

    return ans;

}

  

void init(){//预处理阶乘（快速幂求逆元）

    fact[0] = infact[0] = 1;

    for(int i = 1; i < N; i++){

        fact[i] = fact[i - 1] * i % mod;

        infact[i] = qpow(fact[i], mod - 2, mod) % mod;

    }

}

  
  

signed main(){

    init();

    cin >> n >> m;

    for(int i = 1; i <= n; i++){

        cin >> v[i];

        int tmp = fact[v[i] + m] * infact[m] % mod;

        tmp = tmp * infact[v[i]] % mod;

        res = res * tmp % mod;

    }  

  

    cout << res << endl;

  
  

    return 0;

}
```