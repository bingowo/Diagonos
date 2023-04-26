#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    char s1[500],s2[500];
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int l1=strlen(s1);
        int l2=strlen(s2);
        int l=max(l1,l2);
        int a[l],b[l],c[l];
        for(int i=0;i<l;i++)
        {
            a[i]=0;
            b[i]=0;
            c[i]=0;
        }
        for(int i=l-1;i>=l-l1;i--)
        {
            a[i]=s1[i-l+l1]-'0';
        }
        for(int i=l-1;i>=l-l2;i--)
        {
            b[i]=s2[i-l+l2]-'0';
        }
        if(strcmp(s1,s2)>0)
        {
			for(int i=l-1;i>=0;i--)
        	{
            	if(a[i]>=b[i])
            	{
                	c[i]=a[i]-b[i];
            	}
            	else
            	{
                	c[i]=a[i]+10-b[i];
                	a[i-1]--;
            	}
        	}
        	int t=0;
        	for(int i=0;i<l;i++)
        	{
            	if(c[i]==0)
            	{
                	t++;
            	}
            	else
            	{
                	break;
            	}
        	}
        	for(int i=t;i<l;i++)
        	{
            	printf("%d",c[i]);
        	}
        	printf("\n");
        }
        else if(strcmp(s1,s2)==0)
        {
        	printf("0\n");
		}
		else
		{
			for(int i=l-1;i>=0;i--)
        	{
            	if(b[i]>=a[i])
            	{
                	c[i]=b[i]-a[i];
            	}
            	else
            	{
                	c[i]=b[i]+10-a[i];
                	b[i-1]--;
            	}
        	}
        	int t=0;
        	for(int i=0;i<l;i++)
        	{
            	if(c[i]==0)
            	{
                	t++;
            	}
            	else
            	{
                	break;
            	}
        	}
        	printf("-");
        	for(int i=t;i<l;i++)
        	{
            	printf("%d",c[i]);
        	}
        	printf("\n");
		}
    }
    return 0;
}