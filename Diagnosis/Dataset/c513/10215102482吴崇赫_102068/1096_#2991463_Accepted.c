#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105

typedef struct
{
    int st,tar;
}Ins;

int cmp(const void* a,const void* b)
{
    Ins* ia=(Ins*)a;Ins* ib=(Ins*)b;
    if(ia->st!=ib->st)return ia->st>ib->st?1:-1;
    else return ia->tar>ib->tar?1:-1;
}

int main()
{
    int T;
    scanf("%d\n",&T);
    while(T--){
        int ord_num,ord1[N],ord2[N];
        Ins a[N];
        scanf("%d",&ord_num);int _n=ord_num;
        for(int i=0;i<N;++i)ord1[i]=ord2[i]=0;
        int p=1, j=0;
        while(ord_num--){

            scanf("%d %d",&a[j].st,&a[j].tar);
            ord1[a[j].st]++;ord2[a[j].tar]++;
            ++j;
        }
        for(int i=0;i<N;++i){
            if(ord1[i]&&ord2[i]){
                //printf("Poor dxw!\n");
                p=0;break;
            }
        }
        qsort(a,_n,sizeof(a[0]),cmp);
        for(int i=1;i<_n;++i){
            if(a[i].st==a[i-1].st&&a[i].tar!=a[i-1].tar){p=0;break;}
        }
        if(p)printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;

}
