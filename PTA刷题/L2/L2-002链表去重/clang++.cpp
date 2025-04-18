#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
    string ci;
    int v;
    string ne;
};
map<string, pair<int, string>> q;
set<int> s;
list<node> save;
list<node> removee;
int saveNumber = 0;
int removeNumber = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int asd;
    string start;
    cin >> start >> asd;
    for (int i = 0; i < asd; i++)
    {
        string here, there;
        int value;
        cin >> here >> value >> there;
        q[here].first = value;
        q[here].second = there;
    }

    for (int i = 0; i < asd; i++)
    {
        node temp;
        temp.ci = start;
        temp.v = q[start].first;
        temp.ne = q[start].second;

        if (s.count(abs(q[start].first)))
        {
            (*removee.rbegin()).ne = temp.ci;
            removee.push_back(temp);
            removeNumber++;
        }
        else
        {
            (*save.rbegin()).ne = temp.ci;
            s.insert(abs(q[start].first));
            save.push_back(temp);
            saveNumber++;
        }
        start = q[start].second;
        if (start == "-1")
            break;
    }

    int cnt = 0;
    // cout << "save" << endl;

    for (auto it = save.begin(); it != save.end(); it++)
    {
        cnt++;
        if (cnt >= saveNumber)
            break;
        cout << (*it).ci << ' ' << (*it).v << ' ' << (*it).ne << endl;
    }
    if (saveNumber >= 1)
    {
        cout << (*save.rbegin()).ci << ' ' << (*save.rbegin()).v << " -1" << endl;
    }

    // cout << "remove" << endl;
    cnt = 0;
    for (auto it = removee.begin(); it != removee.end(); it++)
    {
        cnt++;
        if (cnt >= removeNumber)
            break;
        cout << (*it).ci << ' ' << (*it).v << ' ' << (*it).ne << endl;
    }
    if (removeNumber >= 1)
    {
        cout << (*removee.rbegin()).ci << ' ' << (*removee.rbegin()).v << " -1" << endl;
    }

    return 0;
}
