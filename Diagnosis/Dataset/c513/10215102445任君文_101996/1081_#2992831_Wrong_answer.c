#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,n,c=0,t=0;
    int num[110]={0};
    int i,j,k,T,m;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d%d",&a,&n);
        num[0]=a;
        m=1;
        for(j=0;j<n;j++)
        {
            c=0;
            for(k=0;k<m;k++)
            {
                t=num[k]*a+c;
                c=t/10;
                num[k]=t%10;
            }
            if(c!=0)
            {
                num[m]=c;
                m++;
            }
            
        }
        printf("case #%d:\n",i);
        for(j=m;j>=0;j--)
        {
            printf("%d",num[j]);
        }
        printf("\n");
    }
    return 0;
}