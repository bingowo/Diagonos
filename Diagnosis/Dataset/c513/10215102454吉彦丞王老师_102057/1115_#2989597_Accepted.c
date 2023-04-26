#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
	int a,b;
	a=*((int *)pa);
	b=*((int *)pb);
	return a-b;
}
int cmp1(const void *pa,const void *pb)
{
	int a,b;
	a=*((int *)pa);
	b=*((int *)pb);
	return b-a;
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[21];
        scanf("%s",&s);
        int l=strlen(s);
        int a[l];
        int d[l];
        for(int j=0;j<l;j++)
        {
            a[j]=s[j]-'0';
            d[j]=a[j];
        }
        qsort(d,l,sizeof(int),cmp1);
        int t=0;
        for(int j=0;j<l;j++)
        {
        	if(d[j]==a[j])
        	{
        		t++;
			}
		}
		if(t!=l)
        {
			int m=0;
        	int n=0;
        	for(int j=l-2;j>=0;j--)
        	{
            	for(int k=l-1;k>j;k--)
            	{
                	if(a[j]<a[k])
                	{
                		m=j;
                		n=k;
                		int t=a[j];
                		a[j]=a[k];
                		a[k]=t;
                		break;
                	}
                	else
                	{
                		continue;
					}
            	}
            	if(n!=0||m!=0)
            	{
            		break;
				}
        	}
        	int b[l-m-1];
        	for(int j=0;j<l-m-1;j++)
        	{
        		b[j]=a[j+m+1];
			}
			qsort(b,l-m-1,sizeof(int),cmp);
        	printf("case #%d:\n",i);
        	for(int j=0;j<=m;j++)
        	{
        		printf("%d",a[j]);
			}
			for(int j=0;j<l-m-1;j++)
			{
				printf("%d",b[j]);
			}	
			printf("\n");
		}
		else
		{
			int t;
			for(int j=l-1;j>=0;j--)
			{
				if(d[j]>0)
				{
					t=j;
					break;
				}
			}
			int c[l];
			c[0]=0;
			for(int j=0;j<t;j++)
			{
				c[j+1]=d[j];
			}
			for(int j=t+1;j<l;j++)
			{
				c[j]=d[j];
			}
			qsort(c,l,sizeof(int),cmp);
			printf("case #%d:\n",i);
			printf("%d",d[t]);
			for(int j=0;j<l;j++)
			{
				printf("%d",c[j]);
			}
			printf("\n");
		}
    }
    return 0;
} 