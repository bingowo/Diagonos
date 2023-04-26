#include<stdio.h>
#include<stdlib.h>
int add(int n,int t)
{
    int result=0;
    for(int i=n;i>t;i--)
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
	return a-b;
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int a[n];
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        int b[m][2];
        for(int j=0;j<m;j++)
        {
            scanf("%d%d",&b[j][0],&b[j][1]);
        }
        int end[n*(n+1)/2];
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
        qsort(end,n*(n+1)/2,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            int re=0;
            for(int q=b[j][0];q<b[j][1]+1;q++)
            {
                re=re+end[q-1];
            }
            printf("%d\n",re);
        }
    }
    return 0;
}