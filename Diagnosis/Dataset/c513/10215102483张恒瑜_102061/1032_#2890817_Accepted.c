#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    int *a0=(int*)a,*b0=(int*)b,i;
    for(i=0;i<50;i++)
    {
        if(a0[i]!=b0[i]) return b0[i]-a0[i];
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,i,j;
        scanf("%d",&n);
        int input[1010][55]={{-1}};
        for(i=0;i<n;i++)
        {
            int j=0;
            while (scanf("%d",&input[i][j]))
            {
                if(input[i][j]==-1) break;
                else j++;
            }
        }

        qsort(input,n,sizeof(input[0]),cmp);

        for(i=0;i<n;i++)
        {
            int j=0;
            while(input[i][j]!=-1) 
            {
                printf("%d ",input[i][j]);
                j++;
            }
            printf("\n");
        }
        
    }
    return 0;
}