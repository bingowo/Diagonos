#include <stdio.h>
#include <stdlib.h>

/*int cmp(const void *a,const void*b)
{
    int aa=(*(int*)a);
    int bb=(*(int*)b);
    return aa-bb;

}*/

void makenum(int n,int zth,int w[][3],int du[],int re[])
{
    if(zth<n)
    {
        int i,j=zth;
        for(i=0;i<3;i++)
        {
            du[j]=w[zth][i];
            makenum(n,zth+1,w,du,re);
        }
    }
    else
    {
        int k,sum=0;
        for(k=0;k<n;k++)
        {
            sum+=du[k];
        }
        //printf("sum=%d\n",sum);
        if(sum>0) re[sum-1]=1;
        return;
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int w[15][3];
    for(i=0;i<15;i++)
    {
        w[i][1]=0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i][0]);
        w[i][2]=-w[i][0];
    }
    int slen=0,j;
    for(i=0;i<n;i++)
    {
        slen+=w[i][0];
    }
    //printf("slen=%d\n",slen);
    /*for(i=0;i<n;i++)
    {
        printf("w[%d][0]=%d\n",i,w[i][0]);
        printf("w[%d][1]=%d\n",i,w[i][1]);
        printf("w[%d][2]=%d\n",i,w[i][2]);
    }*/
    int re[1200];
    memset(re,0,sizeof(int)*1200);
    //for(i=0;i<slen;i++) printf("%d",re[i]);
    //printf("\n");
    //qsort(w,n,sizeof(int),cmp);
    int mid[15];
    memset(mid,0,sizeof(int)*15);
    makenum(n,0,w,mid,re);
    for(i=0;i<slen;i++)
    {
        printf("%d",re[i]);
    }


    return 0;



}
