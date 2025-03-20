#include<iostream>
using namespace std;
typedef long long ll;
int n,res=0,len=0;//res代表连续因子的起始位置，len代表连续因子的长度
int number(int x)//计算从x起，连续因子的最大长度
{
    int num=0,sum=n;
    for(int i=x;sum!=0;i++)
    {
        if(sum%i==0) num++,sum/=i;
        else break;
    }
    return num;
}
int main()
{
    cin>>n;
    for(int i=2;i<=n/i;i++)//i<=n/i可以防止i*i超过int范围
    {
        int l=number(i);
        if(l>len) res=i,len=l;
    }
    
    
    if(len!=0)//如果长度不为0表示存在连续因子，否则输出 1 换行 n
    {
        cout<<len<<endl;
        
        cout<<res;
        for(ll i=res+1;i<len+res;i++)
        {
            cout<<"*"<<i;
        }
        cout<<endl;
        
    }
    
    else
    {
        cout<<1<<endl;
        cout<<n<<endl;
    }
    
    return 0;
}