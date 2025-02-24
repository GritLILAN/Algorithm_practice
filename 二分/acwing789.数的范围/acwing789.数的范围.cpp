#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, q;
int a[N];

int main(){
    cin >> n >> q;
    for(int i = 0 ; i < n; i++) cin >> a[i];

    while(q--){
        int x;
        cin >> x;

        //先找目标区间的左端点，左端点右边的范围是>=x,所以check条件
        //是a[mid] >= x
        //根据else l = mid + 1, 模板是mid = l + r >> 1
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(a[mid] >= x) r = mid;
            else l = mid + 1; 
        }
        if(a[l] != x){
            cout << "-1 -1" << endl;
            continue;
        }
        cout << l << ' ';

        //找目标区间的右端点，右端点左边范围<=x，所以check条件
        //是a[mid] <= x
        //根据else r = mid - 1, 模板是mid = l + r + 1 >> 1
        l = 0, r = n - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[mid] <= x) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }



    return 0;
}