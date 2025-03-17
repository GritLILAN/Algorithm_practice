### 原题连接
https://ac.nowcoder.com/acm/contest/103948/E
### 题目大意
一共`n`个线段(区间)，初始全部是红色，你要选择一些区间染成紫色，使得同色区间不相交。至少选择一条线段。
结果先输出紫色线段数，再输出线段编号，不存在方案输出`-1`。
### 解题思路
类似线段贪心板子题(最大不相交区间数)，由于要记录排序前的线段编号，所以开结构体存`l, r, idx`三个数据。
维护2个数组和两个变量，`group1[]`存染成紫色的所有区间编号，`group2[]`表示染成红色的所有区间编号；`last1`表示所有紫色区间内的末端点，`last2`表示所有红色区间的末端点。
按照左端点排序后，遍历所有区间，如果当前区间左端点大于`last1`把它染成紫色，否则若大于`last2`把它染成红色，都不满足的话，找不到可行方案输出`-1`退出。

> [!NOTE] 注意
> （1）按照左端点排序的话，为什么板子里需要特殊处理，这个题不需要？因为这个题任意可行方案即可，板子需要找最大数量。
> （2）既然题目说至少选择一个线段染成紫色，那为什么不需要特判所有线段都不相交的情况？因为我们的代码写法是不管三七二十直接染成紫色（第一个if就染成紫色），这种情况最后全染成紫色了。

### 代码
```cpp
#include<bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 5;

  

struct segment{

    int l, r, idx;

};

  

bool cmp(const segment& a, const segment& b){

    return a.l < b.l;

}

  

int n;

vector<segment> v;

  

signed main(){

    cin >> n;

    for(int i = 0; i < n; i++){

        int l, r; cin >> l >> r;

        v.push_back({l, r, i + 1});

    }

  

    sort(v.begin(), v.end(), cmp);

  

    int last1 = -1, last2 = -1;

    vector<int> group1, group2;

    for(int i = 0; i < n; i++){

        //cout << "last1 " << last1 << " last2 " << last2 << endl;

        if(last1 < v[i].l){

            group1.push_back(v[i].idx);

            last1 = v[i].r;

        }

        else if(last2 < v[i].l){

            group2.push_back(v[i].idx);

            last2 = v[i].r;

        }

        else{

            cout << -1 << endl; return 0;

        }

    }

  

    cout << group1.size() << endl;

    for(int i = 0; i < group1.size(); i++){

        cout << group1[i] << ' ';

    }

  

    return 0;

}
```