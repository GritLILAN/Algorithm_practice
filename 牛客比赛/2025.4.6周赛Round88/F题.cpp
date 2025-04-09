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