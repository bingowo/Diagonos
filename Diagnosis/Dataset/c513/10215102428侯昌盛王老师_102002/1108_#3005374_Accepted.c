#include <stdio.h>

int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int r=n*10,count=1,j,flag=0;
		int a[100],s[100],i;
		s[0]=r;
		for(i=0;;i++)
		{
			a[i]=r/m;
			r=r%m;
			r*=10;
			if(r==0) break;
			for(j=0;j<count;j++)
			{
				if(s[j]==r)
				{
					flag=1;
					break;
				}
			}
			if(j!=count) break;
			s[count]=r;
			count++;
		}
		printf("case #%d:\n",e);
		printf("0.");
		int k;
		for(k=0;k<=i;k++) printf("%d",a[k]);
		printf("\n");
		if(flag==1) printf("%d-%d\n",j+1,count);
		//j+1-->count
		
	}
}