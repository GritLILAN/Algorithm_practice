#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;

struct node{
    string id;
    int v;
    string ne;
};

string src;
int  n;
set<int> s;
map<string, pair<int, string> > mp;
vector<node> saved;
vector<node> removed;


int main(){
    cin >> src >> n;
    for(int i = 0; i < n; i++){
        string id , ne;
        int v;
        cin >> id >> v >> ne;
        mp[id].first = v;
        mp[id].second = ne;
    }

    string tmpid = src;
    for(int i = 0; i < n; i++){
        node tmp;
        tmp.id = tmpid;
        tmp.v = mp[tmpid].first;
        tmp.ne = mp[tmpid].second;
        if(s.count(abs(mp[tmpid].first))){
            if(removed.size()) removed[removed.size() - 1].ne = tmp.id;
            removed.push_back(tmp);
        }
        else{
            if(saved.size()) saved[saved.size() - 1].ne = tmp.id;
            s.insert(abs(mp[tmpid].first));
            saved.push_back(tmp);
        }
        tmpid = mp[tmpid].second;
        if(tmpid == "-1") break;
    }

    for(int i = 0; i < saved.size(); i++){
        auto u = saved[i];
        cout << u.id << ' ' << u.v << ' ';
        if(i == saved.size() - 1) cout << -1 << endl;
        else cout << u.ne << endl;
    }
    if (!removed.empty()) {
        removed.back().ne = "-1";
    }
    for(int i = 0; i < removed.size(); i++){
        auto u = removed[i];
        cout << u.id << ' ' << u.v << ' ' << u.ne << endl;
    }



    return 0;
}