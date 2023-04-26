#include <stdio.h>
#include <stdlib.h>
struct data
{
    int x;
    int y;
};
int cmp(const void*a,const void*b)
{
    struct data d1,d2;
    d1=*(struct data*)a;
    d2=*(struct data*)b;
    if(d1.y==d2.y)return(d1.x-d2.x);
    else return(d2.y-d1.y);
}
int main()
{
    struct data d[10000];
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        long long int m=1LL;
        scanf("%d",&d[i].x);
        d[i].y=0;
        for(int n=0;n<64;n++){
            if(d[i].x&m)d[i].y++;
            m=m<<1;
        }
    }
    qsort(d,N,sizeof(d[0]),cmp);
    for(int i=0;i<N;i++)
        printf("%d ",d[i].x);
    return 0;
}