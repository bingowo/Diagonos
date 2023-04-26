#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    char s[27];
    for(int i=0;i<26;i++)
        s[i]='A'+i;
    for(int i=0;i<t;i++)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        int m,j=0;
        int a[100];
        if(n==0) printf("0");
        if(n<0)
        {
            printf("-");
            n=-n;
        }
        while(n>0)
        {
            m=n%r;
            a[j]=m;
            n/=r;
            j++;
        }
        for(int k=j-1;k>=0;k--)
        {
            if(a[k]<10)
                printf("%d",a[k]);
            else {
                int c=a[k];
                printf("%c",s[c-10]);
            }
        }
        printf("\n");
    }
    return 0;
}