#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void reint(int a[],char A[])
{
    int l=strlen(A),i;
    for(i=l-1;i>=0;i--)
        a[l-1-i]=A[i]-'0';
}

void cal(int a[],int b[])
{
    int i,flag=0,t;
    for(i=0;i<505;i++)
        a[i]=a[i]-b[i];
    for(i=504;;i--)
        if(a[i]!=0) break;
    t=i;
    if(a[t]>0)
    {
        for(i=0;i<t;i++)
        {
            a[i]=a[i]-flag;
            if(a[i]<0)
            {
                flag=1;
                a[i]=10+a[i];
            }
        }
        a[t]=a[t]-flag;
    }
    else
    {
        for(i=0;i<t;i++)
        {
            a[i]=a[i]+flag;
            if(a[i]>0)
            {
                flag=1;
                a[i]=a[i]-10;
                a[i]=-a[i];
            }
        }
        a[t]=a[t]+flag;
    }
}

int main()
{
    char A[505],B[505];
    for(;;)
    {
        int a[505]={0},b[505]={0},i,j;
        if(scanf("%s %s",A,B)==EOF) break;
        reint(a,A),reint(b,B);
        cal(a,b);
        for(i=504;i>=0;i--)
            if(a[i]!=0) break;
        for(j=i;j>0;j--)
            printf("%d",a[j]);
        printf("%d\n",a[0]);
    }
    return 0;
}
