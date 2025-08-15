#include<bits/stdc++.h>
using namespace std;
const int N = 110;

int n;
vector<pair<int, pair<int,int> > > student;

bool cmp(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b){
    if(a.second.first != b.second.first) return a.second.first > b.second.first;
    if(a.second.second != b.second.second) return a.second.second < b.second.second;
    return a.first < b.first;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int id, num, penalty;
        cin >> id >> num >> penalty;
        student.push_back(make_pair(id, make_pair(num, penalty)));
    }

    sort(student.begin(), student.end(), cmp);

    for(int i = 0; i < n; i++){
        int id = student[i].first;
        int num = student[i].second.first;
        int penalty = student[i].second.second;
        cout << id << ' ' << num << ' ' << penalty << endl;
    }

    
    return 0;
}