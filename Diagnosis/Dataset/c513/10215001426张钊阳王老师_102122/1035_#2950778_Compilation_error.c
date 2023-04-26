#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll r,h,s;
}a[1001];
bool cmp(node x,node y)
{
    return x.s > y.s;
}
int main()
{
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i].r>>a[i].h;
		a[i].s = 2 * a[i].r * a[i].h;
	}
	sort(a + 1, a + n + 1,cmp);
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		ll sum = a[i].s + a[i].r*a[i].r;
		int count = 1;
		for (int j = 1; j <= n && count < m; j++)
		{
			if (i == j || a[j].r > a[i].r)  continue;
			sum += a[j].s;
			count++;
		}
		if (count == m)
			res = max(res, sum);
	}
	cout<<res<<endl;
	return 0;
}
————————————————
版权声明：本文为CSDN博主「Q&amp;Cui」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_40394960/article/details/109131894