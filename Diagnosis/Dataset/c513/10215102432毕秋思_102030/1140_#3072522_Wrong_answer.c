#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a, const void *b)
{
    if(*(int*)a>*(int*)b) return 1;
    else return 0;
}


int main()
{
	int n,m=0,t=0;
	scanf("%d",&n);
    int a[10001]={0};
    for(int i=0;i<n;i++)
    {
        t+=m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[j+t]);
        }
    }
    int len=t+m;
    qsort(a,len,sizeof(int),cmp);
    int i=1,j=0;
    int b[10001]={0};
    while(i<len)
    {
        if(a[i]==a[i-1])
        {
            b[j]=a[i];
            i++;
            j++;
            while(a[i]==a[i-1])
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    for(int k=0;k<j;k++)
    {
        printf("%d ",b[k]);
    }
	return 0;
}

