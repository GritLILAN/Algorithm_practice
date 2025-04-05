#include<bits/stdc++.h>
using namespace std;

int y, n;

bool check(int a){
    set<int> st;
    int cnt = 0;
    while(a){
        cnt++;
        int t = a % 10;
        a /= 10;
        st.insert(t);
    }
    if(cnt < 4) st.insert(0);
    if(st.size() == n) return true;

    return false;
}

int main(){
    cin >> y >> n;
    int yy = y;
    while(!check(y)){
        //cout << y << endl;
        y++;
    }

    cout << y - yy;
    printf(" %04d", y);

    return 0;
}