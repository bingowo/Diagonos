#include <stdio.h>
#include <stdlib.h>
int main()
{
    int cmp(const void *a,const void *b)
    {
        int *a1=(int *)a,*b1=(int*)b;
        return *a1-*b1;
    }
    long long s[1001]={0},output[50050]={0};
    int input[1001],T;
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n,m,cnt=0,L,U;
        scanf ("%d%d",&n,&m);
        for(int j=1;j<=n;j++) {scanf("%d",s+j);s[j]+=s[j-1];}
        for(int len=1;len<=n;len++)
            for(int k=1;k<=n-len+1;k++)
                output[++cnt]=s[k+len-1]-s[i-1];
        qsort(output,cnt,sizeof(output[0]),cmp);
        for(int k=1;k<=cnt;k++) output[k]+=output[k-1];
        printf("case #%d:\n",i);
        for (int j=0;j<m;j++)
        {
            scanf ("%d%d",&L,&U);
            printf("%d\n",output[U]-output[L-1]);
        }
    }
    return 0;



}
