#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sstu
{
    char num[100];
    int score;
};

int cmp(const void *a,const void *b)
{
    struct sstu *p1,*p2;
    p1=(struct sstu *)a;
    p2=(struct sstu *)b;
    if(p1->score!=p2->score)
        return p2->score-p1->score;
    else
        return strcmp(p1->num,p2->num);
}

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,m,g;
        scanf("%d",&n);
        scanf("%d",&m);
        scanf("%d",&g);
        int a[m];
        struct sstu stu[n];
        int i;
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            scanf("%s",stu[i].num);
            stu[i].score=0;
            int j,i2;
            scanf("%d",&j);
            for(i2=0;i2<j;i2++)
            {
                int i3;
                scanf("%d",&i3);
                stu[i].score+=a[i3-1];
            }
        }
        qsort(stu,n,sizeof(stu[0]),cmp);
        int guo=0;
        for(i=0;i<n;i++)
        {
            if(stu[i].score>=g)
                guo++;
        }
        printf("%d\n",guo);
        for(i=0;i<guo;i++)
        {
            printf("%s %d\n",stu[i].num,stu[i].score);
        }
    }
    return 0;
}
