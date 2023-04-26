#include <stdio.h>
#include <stdlib.h>

int trans(int m,int t)
{
    m=m/2333;
    t++;
    if(m>2332)
    {
        return trans(m,t);
    }
    else
    printf("%d ",m);
    return t;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;a[i]>2332;j++)
        {
            t=0;
            t=trans(a[i],t);
            int m=a[i]/pow(2333,t);
        a[i]=a[i]-m*pow(2333,t);
        }
        if(a[i]==0)
        {
            if(j<t)
                printf("%d ",0);
        }
        printf("%d\n",a[i]);
    }
    return 0;
}
