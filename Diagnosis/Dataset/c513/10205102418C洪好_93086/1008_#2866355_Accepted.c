#include<stdio.h>
void f(int x,int y)
{
	int m,t=0;
		m=x^y;
		while(m)
		{
			m=m&(m-1);
			t++;
		}
	printf("%d\n",t);
}

int main()
{
	int i,T;
	int a[100][2];
	scanf("%d",&T);
	for(i=0;i<T;i++)
		scanf("%d %d",&a[i][0],&a[i][1]);
	for(i=0;i<T;i++)
		f(a[i][0],a[i][1]);
	return 0;
}