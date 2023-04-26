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
        for(int j=0;j<l;j++)
        {
            a[j]=s[j]-'0';
        }
        int m=0;
        int n=0;
        for(int j=l-1;j>0;j--)
        {
            for(int k=j-1;k>=0;k--)
            {
                if(a[j]>a[k])
                {
                	n=j;
                	m=k;
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
    return 0;
} 