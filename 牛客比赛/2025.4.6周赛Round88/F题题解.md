### 题目大意
一共有n个格子，共有$3 \times n$颗石子。往格子上放石子，第`i`个格子放了`a[i]`个石子。需要构造出一个`a[]`序列，使得满足$|(a_{i-1} - a_{i})| = 1$ 且 $|a_{i} - a_{i+1}| = 1$ 。石子可以不用完，但格子不能为空。
给定一个`a[]`序列，若`a[i] != 0`则该元素不能修改，只能修改为0的`a[i]`使得构造出满足要求的序列。如不能构造出来，输出`-1`。
### 解题思路
$\qquad$这个题是双指针贪心的构造题。
$\qquad$核心思路是枚举每个连续为0的区间，对于每个区间，使其趋近于区间右端点那个数。遍历区间过程中，根据`a[i - 1]`和`a[r]`的大小关系动态调整`a[i]`的大小，即如果小了就`+1`，如果大了就`-1`。最后遍历一遍整个数组检查是否满足题目要求即可。
$\qquad$需要分类讨论，首先特判第一个点`a[0] = 0`的情况，找到这个区间的右端点`pm`。如果`a[]`数组全是0，直接构造就行。如果不是，那么找到右端点，将这个区间==从右向左==按照核心思路操作。（为什么是从右向左，因为这种情况没有左端点，只根据右端点1个值去操作）
$\qquad$从刚刚的右端点开始遍历，即`[pm, n-1]`，对于`a[i] == 0`，先找到这个0所在区间的右端点，然后比较左右端点大小，如果左端点>右端点也就是`a[i - 1] > a[j]`那么就`a[i] = a[i - 1] - 1`，反之则`+1`。
$\qquad$最后遍历数组检查是否满足要求即可。
### 代码
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

  

int n;

int a[N];

  

int main(){

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    int pm = 0, r = 0;

    if(a[0] == 0){//特判

        while(pm < n && a[pm] == 0) pm++;

        if(pm == n) for(int i = 0; i < pm; i++) a[i] = i + 1;

        else for(int i = pm - 1; i >= 0; i--){

            if(a[i + 1] > 1) a[i] = a[i + 1] - 1;

            else a[i] = a[i + 1] + 1;

        }

    }

  

    bool in_sec = false;

    for(int i = pm; i < n; i++){

        if(a[i] == 0){

            if(!in_sec){

                r = i;

                while(r < n && a[r] == 0) r++;

                in_sec = true;

            }

            if(a[i - 1] > a[r] && r != n) a[i] = a[i - 1] - 1;

            else a[i] = a[i - 1] + 1;

        }

        else in_sec = false;

    }

  
  

    bool f = true;

    for(int i = 1; i < n; i++){

        if(abs(a[i] - a[i - 1]) != 1) f = false;

        if(!f)break;

    }

  

    if(!f) cout << -1 << endl;

    else{

        for(int i = 0; i < n; i++) cout << a[i] << ' ';

        cout << endl;

    }

    return 0;

}
```