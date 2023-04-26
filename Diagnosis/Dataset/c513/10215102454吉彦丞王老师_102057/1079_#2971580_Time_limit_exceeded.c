#include<stdio.h>
#include<stdlib.h>
long long int add(long long int n,long long int t)
{
    long long int result=0;
    for(long long int i=n;i>t;i--)
    {
        result=result+i;
    }
    return result;
}
int cmp(const void *pa,const void *pb)
{
	int a,b;
	a=*((int *)pa);
	b=*((int *)pb);
	if(a>b)
	{
	    return 1;
	}
	else if(a<b)
	{
	    return -1;
	}
	else
	{
	    return 0;
	}
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        long long int a[n];
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[j]);
        }
        int b[m][2];
        for(int j=0;j<m;j++)
        {
            scanf("%d%d",&b[j][0],&b[j][1]);
        }
        long long int end[n*(n+1)/2];
        for(int j=0;j<n*(n+1)/2;j++)
        {
            end[j]=0;
        }
        for(int k=n;k>0;k--)
        {
            int t=k;
            if(t==n)
            {
                for(int q=0;q<t;q++)
                {
                    end[q]=a[q];
                }
            }
            else
            {
                for(int q=0;q<t;q++)
                {
                    for(int p=0;p<n-t+1;p++)
                    {
                        end[add(n,t)+q]=end[add(n,t)+q]+a[q+p];
                    }
                }
            }
        }
        qsort(end,n*(n+1)/2,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            long long int re=0;
            for(int q=b[j][0];q<b[j][1]+1;q++)
            {
                re=re+end[q-1];
            }
            printf("%lld\n",re);
        }
    }
    return 0;
    
}