#include<bits/stdc++.h>
using namespace std;

string tel;
vector<int> arr;
vector<int> idx;
bool st[10];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    cin >> tel;

    for(int i = 0; i < tel.size(); i++){
        int d = tel[i] - '0';
        if(st[d]) continue;
        arr.push_back(d);
        st[d] = true;
    }
    sort(arr.begin(), arr.end(), cmp);

    map<int, int> mp;
    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]] = i;
    }

    for(int i = 0; i < tel.size(); i++){
        int d = tel[i] - '0';
        idx.push_back(mp[d]);
    }

    cout << "int[] arr = new int[]{";
    cout << arr[0];
    for(int i = 1; i < arr.size(); i++){
        cout << ',' << arr[i];
    }
    cout << "};" << endl;

    cout << "int[] index = new int[]{";
    cout << idx[0];
    for(int i = 1; i < idx.size(); i++){
        cout << ',' << idx[i];
    }
    cout << "};";

    return 0;
}