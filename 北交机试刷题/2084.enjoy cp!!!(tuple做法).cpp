#include<bits/stdc++.h>
using namespace std;
const int N = 110;

int n;
vector<tuple<int, int, int> > student;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
    if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
    return get<0>(a) < get<0>(b);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int id, num, penalty;
        cin >> id >> num >> penalty;
        //student.push_back(id, num, penalty});
        student.push_back(make_tuple(id, num, penalty));
    }

    sort(student.begin(), student.end(), cmp);

    //结构化绑定是C++ 17更新的，C++11不支持
    // for(auto &[id, num, penalty] : student){
    //     cout << id << ' ' << num << ' ' << penalty << endl;
    // }

    for(int i = 0; i < n; i++){
        cout << get<0>(student[i]) << ' ' << get<1>(student[i]) << ' ' << get<2>(student[i]) << endl;
    }
    
    return 0;
}