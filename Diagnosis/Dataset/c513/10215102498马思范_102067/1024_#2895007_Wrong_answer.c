#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int score;
    char id[12];
}student;
int cmp(const void *a,const void *b)
{
    student *x=(student*)a;
    student *y=(student*)b;
    if(x->score!=y->score)
        return y->score-x->score;
    else
        return strcmp(x->id,y->id);
}
int main()
{
    int t;
    int n,m,g;
    int k[11];
    student a[500];
    int tihao;
    int sum;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d%d",&n,&m,&g);
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&k[j]);
        }
        for(int c=0;c<n;c++)
        {
            a[c].score=0;
            scanf("%s%d",&a[c].id,&sum);
            for(int x=0;x<sum;x++)
            {
                scanf("%d",&tihao);
                a[c].score+=k[tihao];
            }
        }
        qsort(a,n,sizeof(a[0]),cmp );
        int pass=0;
        for(int e=0;e<n;e++)
        {
            if(a[e].score>g)
                pass++;
        }
        printf("case #%d:\n",i);
        printf("%d\n",pass);
        for(int d=0;d<pass;d++)
            printf("%s %d\n",a[d].id,a[d].score);
    }
    return 0;
}