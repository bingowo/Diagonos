#include <stdio.h>

int f(int n)
{
	int m,x,y,cnt;
	x=0;y=1;cnt=1;
	while (cnt<n){
		m = y;
		y = x+y;
		x = m;
		cnt++;
	}
	if (n==0) y=0;
	return y;
}

int main()
{
	int T;int a[100];int i;
	scanf("%d",T);
	for (i=0;i<T;i++){
		scanf("%d",a[i]);
		printf("case #%d:\n%d\n",i,f(a[i]));
	}
	return 0;
} 