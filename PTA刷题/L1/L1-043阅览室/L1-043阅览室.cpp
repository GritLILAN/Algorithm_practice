#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
//这个写法是错的，同一本书题目按照最后一次借书为准。
//个人理解是第一个借书的人能借到，但题目不是这样

int n;
bool st[N];//某本书当前是否被借出去
int id, hh, mm;
char op;
char ch;
int hm[N];
int sum = 0;
int num = 0;

void solve(){
    if(op == 'S' && !st[id]){
        hm[id] = 60 * hh + mm;
        st[id] = true;
    }
    else if(op == 'E'){
        if(st[id]){
            num++;
            sum += hh * 60 + mm - hm[id];
            //cout << "tmp " << tmp << endl;
            st[id] = false;
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
            memset(hm, 0, sizeof hm);
            cnt++;
            if(!num) cout << "0 0" << endl; 
            //else cout << num << ' ' << ceil(double(sum) / double(num)) << endl;
            //else printf("%d %.0lf\n",num,(double)sum /num);
            else cout << num << ' ' << round(double(sum) / double(num)) << endl;
            //else cout << fixed << setprecision(0) << double(sum) / num << endl;
            sum = 0;
            num = 0;
            continue;
        }
        solve();
    }

    return 0;
}

/*
3
1 S 08:10
1 S 08:35
1 E 10:00
1 E 13:16
0 S 17:00
0 S 17:00
3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00





*/