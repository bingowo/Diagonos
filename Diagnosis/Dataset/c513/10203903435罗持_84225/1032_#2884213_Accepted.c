#include <stdio.h>
#include <stdlib.h>
struct node
{
	int len;
	int num[60];
};
int mycmp(const void*aa,const void*bb)
{
	struct node a = *(struct node*)aa;
	struct node b = *(struct node*)bb;
	int lim = a.len;
	if(b.len < lim) lim = b.len;
	/*for(int i=1;i<=a.len;i++) printf("%d ",a.num[i]);
	putchar('\n');
	for(int i=1;i<=b.len;i++) printf("%d ",b.num[i]);
	putchar('\n');*/
	for(int i=1;i<=lim;i++)
	{
		if(a.num[i]!=b.num[i])
		{
			if(a.num[i] < b.num[i]) return 1;
			else return -1;
		}
	}
	if(a.len < b.len) return 1;
	else return -1;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		struct node a[1010];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int num;
			a[i].len = 0;
			while(~scanf("%d",&num))
			{
				if(num==-1) break;
				else
				{
					a[i].len++;
					a[i].num[a[i].len] = num;
				}
			}
		}
		qsort(a+1,n,sizeof(a[0]),mycmp);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].len;j++) printf("%d ",a[i].num[j]);
			putchar('\n');
		}
	}
	return 0;
}