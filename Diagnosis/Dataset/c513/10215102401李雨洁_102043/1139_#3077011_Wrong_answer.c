#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int m;
    scanf("%d",&m);
    int a[10000]={1};
    int k =1;
    for(int i=0;i<10000;i++)
    {
        int value=0;
        for(int j=k-1;j>=0;j--) value=value*10+a[j];
        if(m==1)
        {
            printf("10");
            return 0;
        }
        else if(value%m==0)
        {
            printf("%d",value);
            return 0;
        }
        else
        {
            int x=1;
            int  n;
            for(int t=0;t<k;t++)
            {
                n=a[t]+x;
                a[t]=n%2;
                x=n/2;
            }
            if(x==1)
            { a[k]=1; k++; }
        }
    }
    printf("-1");
    return 0;
}
