#include <stdio.h>
#include <string.h>
#define N 30000

int main()
{
    int T,n,r;
    scanf("%d\n",&T);
        while(scanf("%d %d\n",&n,&r)!=EOF)
        {
            if(n<0)
            {
                printf("-");
                n=-n;
            }
            if(n==0)
            {
                printf("0\n");
                continue;
            }
            int m=n,j=0;
            int a[N];
            while(m!=0)
            {
                a[j]=m%r;
                j++;
                m=m/r;
            }
            for(int k=j-1;k>=0;k--)
            {
                if(a[k]>=10)
                    printf("%c",'A'+a[k]-10);
                else printf("%d",a[k]);
            }
            printf("\n");
        }
    return 0;
}
