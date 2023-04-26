#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 10005

typedef struct
{
    int a[N],size;
}show;

void addshow(show* s,int n)
{
    int p=s->size;
    s->a[p++]=n;
    for(int i=0;i<s->size;++i){
        int temp=s->a[i];
        s->a[p++]=temp+n;
        s->a[p++]=abs(temp-n);
    }
    s->size=p;
}

int main()
{
    int n_w,weight[12],sum=0;
    scanf("%d\n",&n_w);
    for(int i=0;i<n_w;++i){scanf("%d",&weight[i]);sum+=weight[i];}
    show ret;
    ret.size=1;ret.a[0]=weight[0];

    for(int i=1;i<n_w;++i){
        addshow(&ret,weight[i]);
    }
    char out[N]={0};
    for(int i=0;i<sum;++i)out[i]='0';
    for(int i=0;i<ret.size;++i)out[ret.a[i]-1]='1';
    printf("%s",out);
    return 0;
}
