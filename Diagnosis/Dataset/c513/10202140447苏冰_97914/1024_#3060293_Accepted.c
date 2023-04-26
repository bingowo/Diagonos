#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct SSS
{
    char name[12];
    int sum;
    int num[15];
    int score;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if(a->score != b->score)
    {
        return b->score - a->score;
    }
    else return strcmp(a->name,b->name);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n,m,g;
        scanf("%d%d%d",&n,&m,&g);
        int a[12];
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
        }
        sss s[n];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int score=0;
            scanf("%s%d",s[i].name,&s[i].sum);
            for(int j=0;j<s[i].sum;j++)
            {
                scanf("%d",&s[i].num[j]);
                score+=a[s[i].num[j]];
            }
            if(score>=g) ans++;
            s[i].score=score;
        }
        printf("case #%d:\n",cas);
        printf("%d\n",ans);
        qsort(s,n,sizeof(sss),cmp);
        for(int i=0;i<n;i++)
        {
            if(s[i].score>=g)
            {
                printf("%s %d\n",s[i].name,s[i].score);
            }
        }
    }
    return 0;
}
