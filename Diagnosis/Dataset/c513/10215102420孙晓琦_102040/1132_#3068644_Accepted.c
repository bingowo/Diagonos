#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
        int n,r;
        char s[100];
        scanf("%d %d",&n,&r);
		int i,k=0,sum=0;
		while(n)
		{
			sum+=n%r;
			n=n/r;
		}
		while(sum)
		{
			if(sum%r>=0&&sum%r<=9)
				s[k++]=sum%r+'0';
			else
				s[k++]=sum%r-10+'A';
			sum=sum/r;
		}
		printf("case #%d:\n",j);
		for(i=k-1;i>=0;i--)
			printf("%c",s[i]);
        printf("\n");
	}
	return 0;
    }