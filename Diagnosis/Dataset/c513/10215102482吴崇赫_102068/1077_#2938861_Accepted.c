#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define N 505

typedef struct
{
    int num;
    int idx;
}number;

int getIndex(int* a,int size,int tag)
{
    for(int i=0;i<size;++i){
        if(a[i]==tag)return i;
    }
    return 501;
}

int cmp(const void* a,const void* b)
{
    number* ma=(number*)a;number* mb=(number*)b;
    if(mb->idx!=ma->idx)return ma->idx>mb->idx?1:-1;
    else return ma->num>mb->num?1:-1;
}

int main()
{
    int mm[N];number nn[N];
    int n,m;
    scanf("%d\n",&m);
    for(int i=0;i<m;++i)scanf("%d",&mm[i]);
    scanf("%d\n",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&nn[i].num);
        nn[i].idx=getIndex(mm,m,nn[i].num);
    }
    qsort(nn,n,sizeof(nn[0]),cmp);
    for(int i=0;i<n;++i){
        printf("%d ",nn[i].num);
    }
    return 0;
}
