### 原题链接
https://ac.nowcoder.com/acm/contest/103151/C
### 题目大意
给定你一个字符串`s`，有`q`次询问，每次询问规定一种字典序，比如字典序前几个字母`c > b > a`而不是`a > b > c`，那么`c`的字典序就会小于`a`。求每次询问中的逆序对数。
### 解题思路
这个题不是常规的求一个数字数组的逆序对，而是字母表。很显然，字母表`2`层for循环也不过`26 * 26`而已，不需要用常规的归并排序，维护一个`cnt[i][j]`数组即可。`cnt[a][b]`表示字母`a`在字母`b`前出现的次数，或者字母`b`在字母`a`后面出现的次数。
预处理代码：
```cpp
    // 预处理：从右向左遍历字符串，填充cnt数组

    for (int i = s.size() - 1; i >= 0; --i) {

        int c = s[i] - 'a';  // 当前字符转换为0-25的索引

        for (int a = 0; a < 26; ++a) {

            cnt[c][a] += count[a];  // 当前字符c后面出现的每个字符a的次数累加

        }

        count[c]++;  // 更新当前字符的出现次数

    }
```
当然正着处理也可以，不过`cnt[c][a] += count[a]`要变成`cnt[a][c] += count[a]`。
对于每次询问，先用`rank[]`数组存一下字母的字典序。2层for循环遍历所有的`cnt[a][b]`，如果`rank[a] > rank[b]`，那答案就加上`cnt[a][b]`。
### 完整代码
```cpp
#include <iostream>

#include <string>

using namespace std;

  

int n, q;

  

int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cin >> n >> q;

    string s;

    cin >> s;

    int cnt[26][26] = {0};  // cnt[a][b]表示字符a在字符b前面出现的次数

    int count[26] = {0};     // 用于记录字符出现次数的临时数组

    // 预处理：从右向左遍历字符串，填充cnt数组

    for (int i = s.size() - 1; i >= 0; --i) {

        int c = s[i] - 'a';  // 当前字符转换为0-25的索引

        for (int a = 0; a < 26; ++a) {

            cnt[c][a] += count[a];  // 当前字符c后面出现的每个字符a的次数累加

        }

        count[c]++;  // 更新当前字符的出现次数

    }

  

    while (q--) {

        string perm;

        cin >> perm;

        int rank[26];

        // 构建rank数组，记录每个字符在排列中的位置

        for (int i = 0; i < 26; ++i) {

            char ch = perm[i];

            rank[ch - 'a'] = i;  // 字符ch的位置是i

        }

        long long ans = 0;

        // 遍历所有字符对(a, b)，统计满足rank[a] > rank[b]的cnt[a][b]之和

        for (int a = 0; a < 26; ++a) {

            for (int b = 0; b < 26; ++b) {

                if (a != b && rank[a] > rank[b]) {

                    ans += cnt[a][b];

                }

            }

        }

        cout << ans << '\n';

    }

    return 0;

}
```