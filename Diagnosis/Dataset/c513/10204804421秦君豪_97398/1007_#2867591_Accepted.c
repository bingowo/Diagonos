#include <stdio.h>
#include<stdlib.h> 
#include<string.h>

int main()
{ 
	int T,n,i,j=0,k,ret=0,cout=0,temp=-1,N;

	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		temp = -1;
		cout = 0;
		j=0;
		ret=0;
		scanf("%d",&n);
		N=n;
		while (N!=0)
		{
			N=N/2;
			j++;
		}
//		printf("j=%d",j);
		for(k=0;k<j;k++)
		{
			if ((n&1)==0)
			{
				if (temp!=0) 
				{
					temp=0;
					cout ++;
				}
				else
				{
					ret=(ret<cout?cout:ret);
					cout=1;
				}
			}
			else 
			{
				if(temp!=1) 
				{
					temp=1;
					cout++;
				}
				else 
				{
					ret=(ret<cout?cout:ret);
					cout=1;
				}
			}
			n=(unsigned int)n>>1; 
		}
		ret=(ret<cout?cout:ret);
		printf("case #%d:\n",i);
		printf("%d\n",ret); 
		
	} 
    return 0;
}
