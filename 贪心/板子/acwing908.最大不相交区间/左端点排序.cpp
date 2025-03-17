#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 5;
//左端点排序需要加一个特殊处理，防止有的特别长的线段左端点靠前。
int n;
int res = 0;

signed main(){
    cin >> n;
    vector<PII> segs(n);
    for(int i = 0; i < n; i++){
        cin >> segs[i].first >> segs[i].second;
    }

    sort(segs.begin(), segs.end());

    int ed = -2e9;
    for(auto seg : segs){
        if(seg.first > ed){
            res++;
            ed = seg.second;
        }
        else{//特殊处理，将ed更新成更小的那个，
            //res不变相当于从选刚刚那个变成选现在这个ed更左的线段了
            ed = min(ed, seg.second);
        }
    }

    cout << res << endl;

    return 0;
}