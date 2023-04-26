#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int find(int s[],int n,int b)
{
	int t=-1;
	for(int i=0;i<=n;i++)
	{
		if(b==s[i])
		{
			t=i;
			break;
		}
	}
	return t;
}
int main()
{
	int number;
	scanf("%d",&number);
	for(int i=0;i<number;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		char s[100];
		int *c=(int *)malloc(100*sizeof(int));
		s[0]='0';
		c[0]=a+'0';
		int num1=1;
		int num2=1;
		int t=0;
		int begin;
		while(1)
		{
			if(a*10%b==0)
			{
				s[num1]=a*10/b+'0';
				c[num2]=0;
				num2++;
				t=1;
				break;
			}
			else
			{
				s[num1]=a*10/b+'0';
				c[num2]=a*10%b;
				a=(a*10)%b;
				if(find(c,num2-1,c[num2])!=-1)
				{
					begin=find(c,num2-1,c[num2]);
					break;
				}
				else
				{
					num1++;
					num2++;
				}
			}
		}
		s[num1+1]='\0';
		free(c);
		if(t==1)
		{
			printf("0.");
			for(int j=1;j<=num1;j++)
			{
				printf("%c",s[j]);
			}
			printf("\n");
		}
		else
		{
			printf("0.");
			for(int j=1;j<=num1;j++)
			{
				printf("%c",s[j]);
			}
			printf("\n");
			printf("%d-%d\n",begin+1,num1);
		}
	}
}