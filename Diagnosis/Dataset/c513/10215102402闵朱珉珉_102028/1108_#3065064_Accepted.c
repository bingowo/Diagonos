#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int T,m,n;
    scanf("%d",&T);
    for (int q=0;q<T;q++)
    {
        scanf("%d%d",&n,&m);
        int s[100]={0},status[100]={0},flag=0;
        printf("case #%d:\n0.",q);
        for (int i=1;!flag;i++)
        {
            if(n==0)
            {
                flag=1;
                for (int j=1;j<i;j++) printf("%d",s[j]);
                printf("\n");
            }
            else
            {
                if (status[n])
                {
                    flag=1;
                    for (int j=1;j<i;j++) printf("%d",s[j]);
                    printf("\n");
                    printf("%d-%d\n",status[n],i-1);
                }
                else
                {
                    status[n]=i;
                    s[i]=n*10/m;
                    n=n*10%m;
                }
            }
        }
    }
    return 0;
}
