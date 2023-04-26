#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long int tran(char str)
{
    int i,k,j,l,a[61];long long int sum=0;
    i=strlen(str);
    if(i==1) return 1;
    else if(i==2) return 2;
    else
    {
        a[0]=1;a[1]=0;
        for(k=2,j=0,l=i;k<i;k++,j++,l--)
        {
            a[k]=k;sum+=a[j]*(int)pow((double)i,l-1);
        }
    return sum;
    }
}
int main()
{
    int i,n;char str[61];long long int sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        printf("case #%d:\n",i);
        printf("%lld",sum);
        printf('\n');
    }
    return 0;
}
