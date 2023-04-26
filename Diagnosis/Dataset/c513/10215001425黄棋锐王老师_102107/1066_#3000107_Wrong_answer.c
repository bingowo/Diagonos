#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int count=0;
void cal(int all,int be,int min,int end)//DFS
{   if(min==0)
   {
       if(be==end) count++;
       return;
    }
	if(be==1)  cal(all,be+1,min-1,end);
	else if(be==all)  cal(all,be-1,min-1,end);
	 else{
	 cal(all,be-1,min-1,end);
	 cal(all,be+1,min-1,end);
	 }
}
int main()
{    int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
 	{   int n,m,p,t;
 		scanf("%d %d %d %d",&n,&p,&m,&t);
 		printf("%d\n",count);
 		count=0;
	}
	return 0;
}