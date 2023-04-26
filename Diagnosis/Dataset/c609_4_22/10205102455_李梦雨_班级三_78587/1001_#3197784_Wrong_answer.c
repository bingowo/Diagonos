#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    char s[]={'A','B','C','D','E','F','G'};
    for(int i=0;i<t;i++)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        int m,j=0;
        char a[100];
        if(n<0)
        {
            printf("-");
            n=-n;
        }
        while(n>1)
        {
            m=n%r;
            if(m>=10)
                a[j]=s[m-10];
            else a[j]=m;
            n/=r;
            j++;
        }
        for(int k=j-1;k>=0;k--)
        {
            printf("%c",a[k]);
        }
        printf("\n");
    }
    return 0;
}