#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{    int k,T;
	scanf("%d\n",&T);
	long long fei[100]={0};
	fei[0]=0;fei[1]=1;fei[2]=1;fei[3]=2;fei[4]=4;fei[5]=7;
	for(k=0;k<T;k++)
 	{    long long ant;
 		int n,i,j;
 		scanf("%d\n",&n);
 		if(n==0) ant=0;
 		else if(fei[n]!=0) ant=fei[n];
 		else
 		{  for(i=0;fei[i]!=-1;i++); 
		 for(;i<=n;i++)
 			{  fei[i]=fei[i-1]+fei[i-2]+fei[i-3];
			 }
			 ant=fei[n];
		 }
		printf("case #%d:\n",k);
		printf("%lld\n",ant);
	}
	return 0;
}
 
