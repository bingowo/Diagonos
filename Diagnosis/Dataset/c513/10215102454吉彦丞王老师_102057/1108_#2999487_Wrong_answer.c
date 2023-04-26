#include<stdio.h>
#include<string.h>
int find(char s[],int n,char c)
{
	int t=-1;
	for(int i=0;i<=n;i++)
	{
		if(s[i]==c)
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
        char c[100];
        c[0]=a+'0';
        int m=a;
        int num=0;
        int n=1;
        int t=0;
        while(1)
        {
        	a=a*10;
        	if(a<b)
        	{
        		a=a*10;
        		s[num]='0';
        		num++;
			}
			else
			{
				if(a%b==0)
				{
					s[num]=a/b+'0';
					num++;
					t=1;
					break;
				}
				else
				{
					s[num]=a/b+'0';
					c[n]=a%b+'0';
					a=a%b;
					num++;
					if(find(c,n-1,c[n])==-1)
					{
						n++;
					}
					else
					{
						break;
					}
				}
			}
		}
		s[num]='\0';
		printf("case #%d:\n",i);
		if(t==1)
		{
			printf("0.%s\n",s);
		}
		else
		{
			printf("0.%s\n",s);
			printf("%d-%d",find(c,n-1,c[n])+1,n);
		}
    }
    return 0;
}