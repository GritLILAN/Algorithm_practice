#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

string s;
string ans;
int a[] = {0, 1, 3, 5, 7, 9, 11, 13, 15, 17};
int h;
int num[15];//第i行有几个字母
char tmp[15][N];
int length;

void show(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < length; j++){
            cout << tmp[i][j];
        }
        cout << endl;
    }
}

void sovle(){
    int len = s.size();
    int n = h * 2 - 2;//一个V字的字母数
    int base = len / n;
    int yu = len % n;
    // cout << "len " << len << endl;
    // cout << "n " << n << endl;
    // cout << "base " << base << endl;
    // cout << "yu " << yu << endl;

    //统计每行有几个字母
    for(int i = 0; i < h; i++){
        //用商值处理每行的基准字母数量
        if(i == 0 || i == h - 1) num[i] = base;
        else num[i] = 2 * base;

        if(yu == 0){
            continue;
        }
        else{
            if(yu > h){
                int x = yu % h;
                if(i == (h - 1 - x)) num[i] += 2;
            }
            else{
                if(i <= (yu - 1)) num[i]++;
            }
        }        
    }

    // for(int i = 0; i < h; i++){
    //     cout << num[i] << endl;
    // }

    //初始化tmp数组
    length = (num[0] + 1) * a[h - 1];
    //cout << "length " << length << endl;
    for(int i = 0; i < h; i++){
        //cout << "i " << i << endl;
        for(int j = 0; j <= length; j++){
            //cout << "j " << j << endl;
            tmp[i][j] = '.';
        }
    }


    int loc = 0;//密文中的下标
    for(int i = 0; i < h; i++){
        int index = i;//每行的下标
        for(int j = 0; j < num[i]; j++){
            tmp[i][index] = s[loc];
            loc++;
            if(i == 0 || i == h - 1) index += a[h - 1] + 1;
            else{
                if(j % 2 == 0){
                    index += a[h - i - 1] + 1;
                }
                else{
                    index += a[i] + 1;
                }
            }
        }
    }

    //show();

    int hh = 0;
    for(int i = 0; i < s.size(); i++){
        ans += tmp[hh][i];
        if(i % n < (h - 1)) hh++;
        else hh--;
    }

    cout << ans << endl;
}

int main(){
    cin >> h;
    cin >> s;

    sovle();



    return 0;
}