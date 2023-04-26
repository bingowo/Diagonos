#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    int a[10];
    for(int cas=0;cas<T;cas++)
    {
        int cnt=0;
        for(int i=0;i<9;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("case #%d:\n",cas);
        for(int i=0,j=8;i<9;i++,j--)
        {
            if(a[i]==0)
            {
                cnt++;
                continue;
            }
            if(a[i]==-1) printf("-");
            else
            {
                if(a[i]>0 && cnt!=i)  printf("+");
                if(a[i]!=1) printf("%d",a[i]);
            }
            if(j==1)
            {
                printf("x");
            }
            else if(j==0)
            {
                if(a[i]==-1 || a[i]==1) printf("1");
            }
            else
            {
                printf("x^%d",j);
            }
        }
        if(cnt==9) printf("0");
        printf("\n");
    }
    return 0;
}
