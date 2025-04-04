#include<bits/stdc++.h>
using namespace std;
const int N = 55;

int n;
pair<int, string> v[N];
bool st[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int gen; string name;
        cin >> gen >> name;
        v[i] = {gen, name};
    }

    int i = 1, j = n;
    int cnt = n;
    while(cnt && i <= n && j >= 1){
        j = n;
        while(v[j].first == v[i].first || st[j]){
            if(j < 1) break;
            //cout << j << endl;
            j--;
        }
        if(v[i].first != v[j].first){
            cnt -= 2;
            st[i] = true; st[j] = true;
            cout << v[i].second << ' ' << v[j].second << endl;
        }
        i++;
    }


    return 0;
}