#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i2a(int a[],int a1)
{
    int hu,j=0;
    if(a1==0)
    {
        a[0]=0;
        return 1;
    }
    while(a1!=0)
    {
        a[j]=a1%10;
        a1=a1/10;
        j++;
    }
    for(int k=0;k<j/2;k++)
    {
        hu=a[k];
        a[k]=a[j-k-1];
        a[j-k-1]=hu;
    }
    return j;
}
int add(int a[],int i,int b[],int j)
{
    int ad=0;
    for(int n=i-1;n>=0;n--)
    {
        if(n>=i-j)
        {
            a[n]=a[n]+b[n-i+j]+ad;
            ad=a[n]/10;
            a[n]=a[n]%10;
        }
        if(n<i-j)
        {
            if(ad==0) break;
            else
            {
                a[n]=a[n]+ad;
                ad=a[n]/10;
                a[n]=a[n]%10;

            }
        }
    }
    if(ad!=0)
    {
        for(int k=i-1;k>=0;k--)
        {
            a[k+1]=a[k];
        }
        a[0]=ad;
        i=i+1;
    }
    return i;
}
int main()
{
    int l,n,i=1,j=1,a[100]={0},b[100]={0},c[100]={0},T,a1=1,b1=0;
    scanf("%d",&T);
    for(int m=0;m<T;m++)
    {
        i=1;j=1;
        i2a(a,a1);
        i2a(b,b1);
        scanf("%d",&n);
        if(n==0)
        {
            printf("case #%d:\n%d\n",m,n);
            continue;
        }
        for(int k=1;k<n;k++)
        {
            for(l=0;l<i;l++)
            {
                c[l]=a[l];
            }
            i=add(a,i,b,j);
            j=l;
            for(l=0;l<j;l++)
            {
                b[l]=c[l];
            }
        }
        printf("case #%d:\n",m);
        for(int k=0;k<i;k++)
            printf("%d",a[k]);
        printf("\n");

    }
    return 0;
}
