#include <stdio.h>
#include <stdlib.h>

int cheng(int re[],int n)
{
    //printf("test:");
    int i,j,jin=0;
    for(i=0;(jin!=0)||(re[i]!=-1);i++)
    {
        if(re[i]==-1) re[i]=0;
        int mid=re[i]*n+jin;
        jin=mid/10;
        re[i]=mid%10;
        //printf("%d",re[i]);
    }
    //printf("\n");
    return i;
}

void reverse(int re[],int wei)
{
    int i;
    for(i=0;i<wei/2;i++)
    {
        int m;
        m=re[i];
        re[i]=re[wei-1-i];
        re[wei-1-i]=m;
    }

    /*for(j=0;j<wei;j++)
    {
        printf("%d",re[j]);
    }
    printf("\n");*/
}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int a,n,j,wei;
        int re[200];
        scanf("%d%d",&a,&n);
        memset(re,-1,sizeof(int)*200);
        re[0]=1;
        for(j=0;j<n;j++)
        {
            wei=cheng(re,a);
        }
        printf("case #%d:\n",i);
        if(n==0) printf("1\n");
        else
        {
            reverse(re,wei);
            for(j=0;j<wei;j++)
            {
                printf("%d",re[j]);
            }
            printf("\n");
        }

    }
    return 0;
}
