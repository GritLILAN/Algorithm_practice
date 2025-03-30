#include<bits/stdc++.h>
using namespace std;

int sum1, sum2;

int main(){
    cin >> sum1 >> sum2;
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for(int i= 0 ;i < n; i++){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int s = a1 + b1;
        if(a2 == s && b2 == s) continue;
        if(a2 == s){
            cnt1++;
            if(cnt1 > sum1){
                cout << 'A' << endl;
                cout << cnt2 << endl;
                return 0;
            }
        }
        if(b2 == s){
            cnt2++;
            if(cnt2 > sum2){
                cout << 'B' << endl;
                cout << cnt1 << endl;
                return 0;
            }
        }
    }




    return 0;
}