#include <stdio.h>
#include<stdlib.h> 
#include<string.h>
void f(unsigned int a,unsigned int b)
{
	int cout=0,i,j;
	unsigned int c=a^b;
	while (c!=0)
	{
		if((c&1)==1)
		{
			cout++;
			c=c>>1;
		}
		else c>>1;
	}
	printf("%d\n",cout);
}



int main()
{ 
	int T,i;
	unsigned int x,y;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{ 
		scanf ("%u%u",&x,&y);
		f(x,y);
	} 
    return 0;
}
