#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    int t;
}node;

int find(int a,int *ch,int len)
{
    for(int i = 0;i < len;i++)
    {
        if(a == ch[i])
            return i+1;
    }
    return 1000;
}

int cmp(const void *a,const void *b)
{
   node *pa = (node*)a;
   node *pb = (node*)b;
   if(pa->t != pb->t)
       return pa->t - pb->t;
   else
       return pa->num - pb->num;
}

int main()
{
    int la;
    scanf("%d",&la);
    int a[la];
    for(int i = 0;i < la;i++)
        scanf("%d",&a[i]);
    int lb;
    scanf("%d",&lb);
    node b[lb];
    memset(b,0,sizeof(b));
    for(int i = 0;i < lb;i++)
    {
        scanf("%d",&b[i].num);
        b[i].t = find(b[i].num,a,la);
    }
    qsort(b,lb,sizeof(b[0]),cmp);
    for(int j = 0;j < lb;j++)
    {
        printf("%d ",b[j].num);
    }

    return 0;
}