#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;//key：书号 value：借书开始的时间（分钟）
map<int,int> flag;//key:书号 value：是否借走（0表示未借走，1表示借走）
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int id,num=0,ans=0,h,m;//num记录借书时间，ans表示借书的次数
        char ch;
        while(scanf("%d %c %d:%d",&id,&ch,&h,&m),id!=0)
        {
            if(ch=='S')//借书
            {
                mp[id]=h*60+m;
                flag[id]=1;
            }
            else if(ch=='E'&&flag[id]==1)//还书
            {   
                num+=h*60+m-mp[id];
                ans++;
                flag[id]=0;
            }
        }
        mp.clear();//清空
        flag.clear();//清空
 
        if(ans!=0) printf("%d %.0lf\n",ans,(double)num/ans);//分情况讨论
        else cout<<0<<" "<<0<<endl;
    }
    return 0;
}