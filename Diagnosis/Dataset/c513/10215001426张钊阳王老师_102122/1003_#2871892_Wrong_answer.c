#include <stdio.h>
#include <stdlib.h>
struct jud
    {
        long long x1;
        long long x;
        int count;
    };
int cmp(const void *a ,const void *b)
{
    struct jud aa,bb;
    aa=*((struct jud*)a);
    bb=*((struct jud*)b);
    if(bb.count==aa.count)
       if(aa.x1<0&&bb.x1<0)
        return aa.x1-bb.x1;
        else return bb.x1-aa.x1;
    else return bb.count - aa.count ;
}
int main()
{
    struct jud
    {
        long long x1;
        long long x;
        int count;
    };
    int m,i,j,t,k;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&k);
        struct jud jud[k];
        for(int s=0;s<k;s++)
            jud[s].count=0;
        for(j=0;j<k;j++)
        {
            scanf("%lld",&jud[j].x);
            jud[j].x1=jud[j].x;
            if(jud[j].x>0)
            {
                while(jud[j].x!=0)
                {
                    if(jud[j].x%2==1) jud[j].count++;
                    jud[j].x=jud[j].x/2;
                }
            }
            if(jud[j].x<0)
            {
                jud[j].x=-jud[j].x;
                while(jud[j].x)
                {
                    if(jud[j].x%2==1) jud[j].count++;
                    jud[j].x=jud[j].x/2;
                }
                jud[j].count=63-t+1;
            }
        }
        qsort(jud,k,sizeof(jud[0]),cmp);
        printf("case #%d:\n",i);
        for(t=0;t<k;t++)
            printf("%lld ",jud[t].x1);
        printf("\n");
    }
    return 0;
}

