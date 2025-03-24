### 原题链接
https://ac.nowcoder.com/acm/contest/104637/D
### 题目大意
有一个数字集合，初始有2个正整数`x`和`y`，每轮操作可以从集合中任选`a, b`两个数字进行如下操作中的一种（操作完将结果加入集合）：
- 与运算`a & b`
- 或运算`a | b`
- 异或`a ^ b`
- 最大公约数`gcd(a,b)`
求经过多少轮操作，使得集合中出现数字`0`。
### 解题思路
#### 方法1（暴力）
首先有一种暴力的思路，就是用`bfs`做。为什么暴力能过方法2会讲。直接上代码：
```cpp
#include<bits/stdc++.h>

using namespace std;

//vec是集合，cnt维护当前是第几次操作

  

int main(){

    int t; cin >> t;

    while(t--){

        int x, y; cin >> x >> y;

        queue<pair<pair<int, int>, int> > q;

        vector<int> vec{x, y};

  

        q.push({{x, y}, 0});

        while(q.size()){

            auto [u, cnt] = q.front();

            auto &[x, y] = u;

            q.pop();

            if((x & y) == 0 || (x | y) == 0 || (x ^ y) == 0){

                cout << cnt + 1<< endl; break;

            }

            int g = __gcd(x, y);

            int a[4] = {x & y, x | y, x ^ y, g};

            for(auto num : vec){

                for(int i = 0; i < 4; i++){

                    q.push({{num, a[i]}, cnt + 1});

                }

            }

            for(int i = 0; i < 4; i++){

                vec.push_back(a[i]);

            }

        }

  

    }

  

    return 0;

}
```
#### 方法2（正解）
观察4种操作，发现或操作(or)会让数据一直增大，最后肯定不是`0`，所以直接不考虑进行这种操作。
接着发现有一种构造方法，可以直接在3步之内得到0。即对`x, y`进行任意一种操作`op`，假设前两次操作的结果是`z`，第三步`z xor z = 0`结束。
那么知道了保底是`3`步之后，我们需要判断比3步少的情况。
1步的情况：要么`x ^ y = 0`，要么`x ^ y = 0`。
2步的情况：
①and xor
②and gcd
③and and
④xor and
⑤xor gcd 
⑥xor xor
⑦gcd and
⑧gcd xor
⑨gcd gcd
首先最后一步肯定不会是`gcd`，因为最大公约数不可能是`0`,排除②⑤⑨。
其次连续同种操作也不行，原因造数据试一下就能看出来，排除③⑥。
只剩下①④⑦⑧这4种情况，枚举即可。
代码如下：
```cpp
#include<bits/stdc++.h>

using namespace std;

//最多3步，x op y = z, x op y = z, z xor z = 0

//or只会变大，直接不考虑

  

int x, y;

  

int solve(){

    if((x & y) == 0 || (x ^ y) == 0) return 1;

    int XOR = x ^ y, AND = x & y, GCD = __gcd(x, y);

    if((x & XOR) == 0 || (y & XOR) == 0) return 2;

    if((x ^ AND) == 0 || (y ^ AND) == 0) return 2;

    if((x & GCD) == 0 || (y & GCD) == 0) return 2;

    if((x ^ GCD) == 0 || (y ^ GCD) == 0) return 2;

    return 3;

}

  

int main(){

    int t; cin >> t;

    while(t--){

        cin >> x >> y;

        cout << solve() << endl;

    }

  

    return 0;

}
```