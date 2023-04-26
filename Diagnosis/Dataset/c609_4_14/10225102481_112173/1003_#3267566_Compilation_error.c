#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    while((t--)!=0)
    {
        double n;
        int m,j,i=0;
        int a[1000],s[1000];
        scanf("%d\n",&n);
        while(n!=0){a[i]=n%2333;n/=2333;i++;}
        for(j=0,m=i;j<=m/2;j++)
            {s[j]=a[i];printf("%d ",s[j]);i--;}
       

    }

    return 0;
}
