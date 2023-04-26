#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long int tran(char str[],int i)
{
    int k,j,l,a[61];long long sum=0;
    if(i==1) return 1;
    else if(i==2) return 2;
    else
    {
        a[0]=1;a[1]=0;
        sum=(int)pow((double)i,i-1);
        for(k=2,l=i-2;k<i;k++,l--)
        {
            a[k]=k;sum+=a[k]*(int)pow((double)i,(double)l-1);
        }
    return sum;
    }
}
int main()
{
    int i,n,a;char str[61];long long sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        a=strlen(str);
        printf("case #%d:\n",i);
        sum=tran(str,a);
        printf("%lld\n",sum);
    }
    return 0;
}
