#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    while((t--)!=0)
    {
        long long int n;
        int m,j,i=0;
        int a[1000],s[1000];
        scanf("%lld\n",&n);
        if(n==0)printf("%d",0);
        while(n>0){a[i]=n%2333;n/=2333;i++;}
        for(j=0,m=i,i--;j<=m-1;j++)
            {s[j]=a[i];printf("%d ",s[j]);i--;}
        
        putchar(10);

    }

    return 0;
}
