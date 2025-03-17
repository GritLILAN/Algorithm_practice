#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int l, r, idx;
};

bool cmp(const Segment& a, const Segment& b) {
    return a.l < b.l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Segment> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].l >> segs[i].r;
        segs[i].idx = i + 1;
    }
    sort(segs.begin(), segs.end(), cmp);

    vector<int> groupA, groupB;
    int lastA = -1, lastB = -1;

    for (auto& seg : segs) {
        if (seg.l > lastA) {
            groupA.push_back(seg.idx);
            lastA = seg.r;
        } else if (seg.l > lastB) {
            groupB.push_back(seg.idx);
            lastB = seg.r;
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }

    if (!groupA.empty() && !groupB.empty()) {
        cout << groupA.size() << '\n';
        for (int x : groupA) cout << x << ' ';
        cout << '\n';
        return 0;
    }

    bool is_independent = true;
    int last = -1;
    for (auto& seg : segs) {
        if (seg.l < last) {
            is_independent = false;
            break;
        }
        last = seg.r;
    }

    if (is_independent && n >= 1) {
        cout << 1 << '\n';
        cout << segs[0].idx << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
