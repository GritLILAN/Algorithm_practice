#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 130;

int n;
int a[N];
queue<PII> q;

int main(){
    cin >> n;
    for(int i = 1; i <= (1 << n); i++){
        cin >> a[i]; q.push({i, a[i]});
    }

    while(q.size() > 2){
        auto t1 = q.front();
        q.pop();
        auto t2 = q.front();
        q.pop();

        if(t1.second > t2.second) q.push(t1);
        else q.push(t2);

    }

    auto t1 = q.front();
    q.pop();
    auto t2 = q.front();
    if(t1.second < t2.second) cout << t1.first << endl;
    else cout << t2.first << endl;



    return 0;
}