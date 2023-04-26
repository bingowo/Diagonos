#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cal(int all,int be,int min,int end)
{   if(min==0&&be==end) return 1;
	else if(min==0&&be!=end) return 0;
	if(be==1) return cal(all,be+1,min-1,end);
	else if(be==all) return cal(all,be-1,min-1,end);
	return cal(all,be-1,min-1,end)+cal(all,be+1,min-1,end);
}
int main()
{    int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
 	{   int n,m,p,t;
 		scanf("%d %d %d %d",&n,&p,&m,&t);
 		int w=cal(n,p,m,t);
 		printf("%d\n",w);
	}
	return 0;
}