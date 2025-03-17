### 原题链接
https://ac.nowcoder.com/acm/contest/103948/D
### 题目大意
$\qquad$双生串定义：当且仅当字符串种每种字符出现偶数次。
$\qquad$有一个长度`n`的`01`字符串，小红先手任意删除非空前缀，小紫接着删除一个后缀(可空串)，如果最终可以生成非空双生串，小紫获胜。
$\qquad$小红随机任意选前缀，小紫可以找最优解，即对于某一个小红操作后的字符串，只要有可行方案，这种情况小紫获胜。求小紫获胜概率。
### 解题思路
$\qquad$首先考虑时间复杂度，数据范围$1 \leq n \leq 10^6$，暴力的话，小红有`n`种选择前缀的可能性，小紫想要找最优解也是遍历剩下的字串，时间复杂度大约$O(n^2)$，所以要预处理前缀和。
$\qquad$这个题的前缀和比较特殊，用二进制表示`0 1`的奇偶性，首先前缀和有4种状态，`00, 01, 10, 11`高位表示`0`的奇偶性，低位表示`1`的奇偶性。
$\qquad$用2个变量更新奇偶性，从左到右遍历，`pre0`表示当前`0`的奇偶性，`pre0 = 0`表示偶数，`pre0 = 1`表示偶数。`pre1`同理。
$\qquad$前缀和数组`pre_states[]`用`pre0 pre1`来组合，`pre_states[i] = pre << 1 | pre1`，这样就组成了两位二进制数表示的状态。
$\qquad$最后遍历一遍所有小红操作后的子串(一共n种情况)，如果后面存在一个`j > i`且满足`pre_states[j] = pre_states[i]`，说明在区间`[i + 1, j]`内`0`和`1`都是偶数个，也就意味着后面有字串满足条件，小紫能获胜，`res++`。
$\qquad$前缀和性质解释：若`pre_states[i - 1] = pre_states[j]`，那么`pre_states[i - 1]`与`pre_states[j]`的高位和低位异或都为`0`，说明区间`[i, j]`内`0`和`1`的个数都是偶数。
$\qquad$最后一个问题，如何`O(1)`的时间找到满足条件的`j`，只需用`max_index[4]`数组维护一下四个状态出现的最后位置即可（因为小紫操作的是后缀，所以只需要知道最后的位置就能判断了）。若最后位置 >`i`，说明小红删剩下的子串里有满足条件的区间。
### 代码
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

  

int n;

string s;

int pre0 = 0, pre1 = 0;//0奇偶性的前缀，1奇偶性的前缀

int pre_states[N];

//状态前缀和，一共4种状态

//00表示有偶数个0偶数个1，01表示有偶数个0奇数个1，

//10表示有奇数个0，11表示有奇数个0奇数个1

int max_index[4] ={-1, -1, -1, -1};

//4种状态的最大下标位置

int cnt = 0;

  
  

int main(){

    cin >> n; cin >> s;

    for(int i = 1; i <= n; i++){

        int c = s[i - 1] - '0';

        if(c == 0) pre0 ^= 1;

        else pre1 ^= 1;

        pre_states[i] = pre0 << 1 | pre1;

        max_index[pre_states[i]] = i;

    }

  

    for(int i = 1; i <= n; i++){

        int state = pre_states[i];

        if(max_index[state] > i) cnt++;

    }

  

    double res = (double)cnt / n;

  

    //printf("%.10lf\n", res);

    cout << res << endl;

  

    return 0;

}
```