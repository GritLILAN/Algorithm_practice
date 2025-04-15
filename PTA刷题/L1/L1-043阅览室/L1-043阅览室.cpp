#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

int n;
bool st[N];//某本书当前是否被借出去
int id, hh, mm;
char op;
char ch;
int h[N], m[N];
int sum = 0;
int num = 0;

void solve(){
    if(op == 'S' && !st[id]){
        h[id] = hh;
        m[id] = mm;
        st[id] = true;
    }
    else if(op == 'E'){
        int tmp = 0;
        if(st[id]){
            num++;
            if(m[id] <= mm){
                tmp += mm - m[id];
                //cout << tmp << ' ';
            }
            else{
                tmp += 60 + mm - m[id];
                //cout << tmp << ' ';
                hh--;
            }
            tmp += (hh - h[id]) * 60;
            //cout << "tmp " << tmp << endl;
            sum += tmp;
        }
    }

}


int main(){
    cin >> n;
    int cnt = 0;

    while(cnt < n){

        cin >> id >> op >> hh >> ch >> mm;
        //cout << id << ' ' << op << ' ' << hh << ' ' << mm << endl;
        if(id == 0){
            memset(st, false, sizeof st);
            cnt++;
            if(!num) cout << "0 0" << endl; 
            else cout << num << ' ' << ceil(double(sum) / double(num)) << endl;
            sum = 0;
            num = 0;
            continue;
        }
        solve();
    }




    return 0;
}