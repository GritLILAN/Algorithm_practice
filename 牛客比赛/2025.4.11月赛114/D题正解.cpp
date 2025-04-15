#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N  =200100;
ll a[N],b[N],c[N];
int main()
{
	int t = 1;
//	cin >> t;
	while(t --)
	{
		ll n,k;
		cin >> n >> k;
		b[0] = 0;
		for(int i = 1; i <= n ; i ++)
		{
			cin >> a[i];
			b[i] = b[i-1] + a[i];
		}
        for(int i = 1; i <= n ; i ++)
        {
            b[i] = max(b[i],b[i-1]);
        }
		c[0] = 0;
		ll s1 = 1;
		for(int i = n ; i >= 1; i --)
		{
			c[s1] = c[s1 - 1]+a[i];
			s1++;
		}
		for(int i = 1; i <= n ; i ++)
		{
			c[i] = max(c[i-1],c[i]);
		}
		ll sum = 0;//摸牌数 
		while(k >= sum)
		{
			k = k - sum + 1;
			sum++;
            if(sum >= n) break;
		}
		sum = min(sum,n);
		ll ans = 0;
		for(int i = 0 ; i <= sum ; i ++)
		{
			
			ans = max(ans,b[i] + c[sum - i]);
		
		}
		cout << ans;
	}
}