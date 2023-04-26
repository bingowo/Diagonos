#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
   char num[11];
   long long sum;
}stu;
int cmp(const void *a,const void *b)
{
    stu p=*((stu *)a);
    stu q=*((stu *)b);
    if(p.sum!=q.sum)
    {
       if (q.sum<p.sum) return -1;
       else return 1;
    }
    else return strcmp(p.num,q.num);
}
int main()
{
    int T,N,M,cnt[11]={0};
    long long G,a[11];
    stu s[505];
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d %d %lld",&N,&M,&G);
        for(int j=1;j<=M;j++)
        {
            scanf("%lld",&a[j]);
        }
        for(int k=0;k<N;k++)
        {
            int solve;
            scanf("%s",s[k].num);
            scanf("%d",&solve);
            if(solve==0) s[k].sum=0;
           while(solve!=0)
           {
               int h;
               scanf("%d",&h);
               s[k].sum+=a[h];
               solve--;
           }
           if(s[k].sum>=G) cnt[cas]++;
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n",cas);
        printf("%d\n",cnt[cas]);
        for(int l=0;l<N;l++)
        {
            if(s[l].sum>=G)
                printf("%s %lld\n",s[l].num,s[l].sum);
        }
    }
    return 0;
}
