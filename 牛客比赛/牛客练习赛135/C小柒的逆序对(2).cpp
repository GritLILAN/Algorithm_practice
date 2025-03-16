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
    int cnt[26][26] = {0};  // cnt[a][b]表示字符a在字符b前面出现的次数
    int count[26] = {0};     // 用于记录字符出现次数的临时数组
    
    // 预处理：从右向左遍历字符串，填充cnt数组
    for (int i = s.size() - 1; i >= 0; --i) {
        int c = s[i] - 'a';  // 当前字符转换为0-25的索引
        for (int a = 0; a < 26; ++a) {
            cnt[c][a] += count[a];  // 当前字符c后面出现的每个字符a的次数累加
        }
        count[c]++;  // 更新当前字符的出现次数
    }
    

    while (q--) {
        string perm;
        cin >> perm;
        int rank[26];
        // 构建rank数组，记录每个字符在排列中的位置
        for (int i = 0; i < 26; ++i) {
            char ch = perm[i];
            rank[ch - 'a'] = i;  // 字符ch的位置是i
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
