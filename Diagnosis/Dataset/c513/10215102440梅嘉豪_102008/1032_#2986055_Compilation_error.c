#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

int main()
{
    int t;
    scanf("%d",&t);
    int num[1000][51];
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;;j++)
            {
                scanf("%d",num[i][j]);
                if(num[i][j]==-1)   break;
            }
        }
        qsort(*num,n,sizeof(int)*51,cmp);
        for(int i=0;i<n;i++)
        {
            printf("%d",num[0][0]);
            for(int j=1;;j++)
            {
                if(num[i][j]==-1)
                {
                    printf(" \t");
                    break;
                }
                printf(" %d",num[i][j]);
            }
        }
    }
}