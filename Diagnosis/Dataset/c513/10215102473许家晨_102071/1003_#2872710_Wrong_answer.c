#include<stdio.h>
#include<stdlib.h>
int cnt(int x)
{
    int cnt=0,jud=0;
    if (x<0)jud=1,x=-x;
    while(x)
    {
        if(x%2==1)cnt++;
        x=x/2;
    }
    if(jud)cnt=65-cnt;
    return cnt;
}
int cmp(const void *a,const void *b)
{
    int *pa=(int*)a;
    int *pb=(int*)b;
    int cnta=cnt(*pa);
    int cntb=cnt(*pb);
    return cnta==cntb?*pa-*pb:cntb-cnta;
}
int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while(T)
    {
        int N;
        int i=0;
        scanf("%d",&N);
        int n=N;
        int *a=(int*)malloc(N*sizeof(int));
        while(N)
        {
            scanf("%d",&a[i]);
            
            i++;
            N--;
        }
        qsort(a,n,sizeof(int),cmp);
        printf("case #%d:\n",cnt);
        for(i=0; i<n; i++)
        {
            printf("%d",a[i]);
            if(i!=N-1)printf(" ");
            else
            {
                printf("\n");
            }
        }
        T-=1;
        cnt++;
        free(a);
    }

    return 0;
}