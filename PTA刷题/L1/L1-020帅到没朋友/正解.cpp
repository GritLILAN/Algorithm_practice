#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
//注意输出的时候前导零问题

int n,m;

int main(){
    cin >> n;
    while(n--){
        int k, id;
        cin >> k;
        for(int i =  0; i < k; i++){
            cin >> id;
            mp[id] = max(mp[id], k);
        }
    }

    int f = 0;
    cin >> m;
    while(m--){
        int q;
        cin >> q;
        if(mp[q] < 2){
            if(f) cout << ' ' << setw(5) << setfill('0') << q;
            else cout << setw(5) << setfill('0') << q;
            mp[q] = 2;
            f = 1;
        }
    }

    if(!f) cout << "No one is handsome" << endl;



    return 0;
}