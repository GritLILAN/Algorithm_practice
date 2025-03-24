### 原题链接
https://ac.nowcoder.com/acm/contest/104637/C
### 题目大意
有一个长度为`n`的`01`串，小苯可以进行“消除”操作，如果`2`个连续字符相同，则可以消除他们。消除次数没有限制，直到不能消除为止。在消除之前，还可以进行“修改”操作，可以选择任意字符，将其改为`0`或`1`。
问需要进行几次“修改”操作，才能使得最后“消除”后`s`的长度不超过`1`。
### 解题思路
直接贪心地消除所有相邻的可消除字符，最后剩下`01`相间的串如`0101010`，这个串需要修改`length / 2`次。
消除的过程可以用`stack`来模拟。
### 代码
```cpp
#include<bits/stdc++.h>

using namespace std;

  

int main(){

    int t;

    cin >> t;

    while(t--){

        int n; string s;

        cin >> n >> s;

        stack<char> stk;

        for(int i = 0; i < s.size(); i++){

            if(stk.size() && s[i] == stk.top()){

                stk.pop();

            }

            else stk.push(s[i]);

        }

  

        cout << stk.size() / 2 << endl;

    }

  

    return 0;

}
```