#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    while((t--)!=0)
    {
        int n,m,j,i=0;
        char a[1000],s[1000];
        scanf("%d\n",&n);
        while(n!=0){a[i]=n%2333;n/=2333;a[i++]=' ';i++;}
        for(j=0,m=i;j<=m;j++)
            {s[j]=a[i];printf("%d\n",s[j]);i--;}

    }

    return 0;
}
