#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{

    char num[20];
    int sum;
};

int main()
{
    int cmp(const void *a1,const void *b1);
    int m;
    scanf("%d",&m);
    for(int z;z<m;z++)
    {
        int n,m,g,i,pass=0;
        int count;
        int flag;
        int point[10];
        scanf("%d %d %d\n",&n,&m,&g);
        for(int t=0;t<m;t++)
            scanf("%d",&point[t]);
        struct student k[500];
        for(i=0;i<n;i++)
        {
            k[i].sum=0;
            scanf("%s",k[i].num);
            scanf("%d",&count);
            for(int t=0;t<count;t++)
                {
                    scanf("%d",&flag);
                    k[i].sum+=point[flag-1];
                }
        }
        for(int s=0;s<n;s++)
        {
            if(k[s].sum>=g) pass++;
        }
        qsort(k,n,sizeof(k[0]),cmp);
        printf("case #%d:\n",z);
        printf("%d\n",pass);
        for(int p=0;p<pass;p++)
        {
            printf("%s ",k[p].num);
            printf("%d\n",k[p].sum);
        }
    }
    return 0;
}


int cmp(const void *a1,const void *b1)
{
    struct student a=*(struct student*)a1;
    struct student b=*(struct student*)b1;
    if(a.sum>b.sum) return -1;
    else if(a.sum<b.sum) return 1;
    else return strcmp(a.num,b.num);
}
