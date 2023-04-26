#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cal(int n)
{ int i=0,k;
	int c00[22]={0};
	int c01[22]={0};
	int  c1[22]={0};
	c00[3]=2;c01[3]=2;c1[3]=3;
	for(i=4;i<=n;i++)//求n时的个数，递推 ,找项的一些公共特征进行分类 
	{ c00[i]=c01[i-1]+c00[i-1];
	  c01[i]=c1[i-1];
	  c1[i]=c00[i-1]+c1[i-1]; 
	}
	k=c00[n]+c01[n]+c1[n];
	return k;
}

 int main()
 {    int n;
	 while(scanf("%d\n",&n)&&n!=-1)
	 {
	 	int k=cal(n);
	 	printf("%lld\n",k);
	 }
		return 0;
}