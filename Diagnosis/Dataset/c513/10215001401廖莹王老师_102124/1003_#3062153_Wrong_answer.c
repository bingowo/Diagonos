#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long a;
    int num;
}data;
int cmp(const void*a,const void*b)
{
    data *k1,*k2;
    k1=(data*)a;k2=(data*)b;
    if(k1->num>k2->num)return -1;
    else if(k1->num<k2->num)return 1;
    else
    {
        if(k1->a>k2->a)return 1;
        else return -1;
    }
}
void jisuan(int h)
{
    int n,i;
    data p[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&p[i].a);p[i].num=0;}
    for(i=0;i<n;i++)
    {
        int d=1,t=0;
        for(t=0;t<64;t++){if((p[i].a&d)!=0)p[i].num++;d=d<<1;}
    }

    qsort(p,n,sizeof(p[0]),cmp);
    printf("case #%d:\n",h);
    for(i=0;i<n;i++)printf("%d ",p[i].a);
    printf("\n");
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
    return 0;
}
