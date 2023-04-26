#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		int large=1,small=1;
		long long ANS=1;
		if(m-n>n)
		{
			small=n;
			large=m-n;
		}
		else{
			small=m-n;
			large=n;
		}
		
		for(int i=m;i>large;i--)
		{
			if(i==2*small)
			{
				ANS=ANS*2;
				small--;//！！！ 
			}
			else{
				ANS=ANS*i;
			}
		}
		
		while(small>1)
		{
			ANS/=small;
			small--;//！！！ 
		}
		
		printf("case #%d:\n",i);
		printf("%lld\n",ANS);
		
	}
}