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