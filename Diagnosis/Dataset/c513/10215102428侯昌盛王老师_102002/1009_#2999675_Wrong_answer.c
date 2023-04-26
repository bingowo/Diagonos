#include <stdio.h>
#include <string.h>
int main()
{
	int n,t;
	scanf("%d",&n);
	fflush(stdin);
	for(t=0;t<n;t++)
	{
		char s[121];
		gets(s);
		int len=strlen(s);
		//printf("%d\n",len);
		int count=0,i,d=1,sum=0;
		for(i=0;i<len;i++)
		{
			d=1;
			int k=sizeof(s[i]),j=0;
			//printf("k=%d\n",k);
			sum+=(k*8);
			for(j;j<(k*8);j++)
			{
				//printf("ll=%d\n",s[i]&d);
				if((s[i]&d)>0) count++;
				d=d<<1;
				//printf("d=%d\n",d);
			}
			
		}
		int e=1;
		//printf("%d %d\n",count,sum);
		while(e<=count)
		{
			if(count%e==0&&sum%e==0)
			{
				count=count/e;
				sum=sum/e;
				e=1;
			}
			e++;
		}
		printf("%d/%d\n",count,sum);
	}
	return 0;
}