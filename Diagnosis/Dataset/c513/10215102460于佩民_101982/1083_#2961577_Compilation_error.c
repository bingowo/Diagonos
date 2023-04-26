#include<stdio.h>  
int T;
void solve()
{
	int n;
	scanf("%d",&n);
	int ret=0;
	int m=5;
	while(n>=m)
	{
		ret+=n/m;
		m*=5;
	}
	printf("%d\n",&n);
}
int main()
{
	scanf("%d",&T);
	for(int step=0;step<T;step++)
	{
		printf("case #%d:\n",step);
		solve();
	}
	return 0;

————————————————
版权声明：本文为CSDN博主「sunshine_lyn」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/sunshine_lyn/article/details/79425664