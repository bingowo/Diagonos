#include <stdio.h>
#include <math.h>

int main()
{   int count(long long int x);
    void swap(int e,int r);
    long long int a[10][10],b[10];
    int i,j,l,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        for(j=0;j<b[i];j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<b[i];j++)
        {
            for(l=j+1;l<b[i];l++)
            {
                swap(a[i][j],a[i][l]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        for(j=0;j<b[i];j++)
        {
            printf("%d ",a[i][j]);
        }
    }

    return 0;
}
int count(long long int x)
{   int w=0;
    long long int q=pow(2,32)-1;
    if(x<0)
    {
        x=x^q+1;
    }
    while(x)
    {
        if(x%2==1)w++;
        x=x/2;
    }
    return x;
}
void swap(int e,int r)
{
    int u;
    if(count(e)<count(r))
    {
        u=e;
        e=r;
        r=u;
    }
    if(count(e)==count(r))
    {
        if(e<r)
        {
            u=e;
            e=r;
            r=u;
        }
    }
}
