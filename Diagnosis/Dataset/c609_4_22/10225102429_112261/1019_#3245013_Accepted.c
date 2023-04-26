#include <stdio.h>
#include <stdlib.h>
#define N 1000000
typedef struct{
    int cnt,num;
}Int;
Int a[N];
int cmp(const void*a, const void* b){
    int cnta = (*(Int*)a).cnt,cntb = (*(Int*)b).cnt;
    int numa = (*(Int*)a).num,numb = (*(Int*)b).num;
    if(cnta!=cntb){
        return cntb-cnta;
    }
    return numa-numb;
}
int main()
{
    int i = 0;
    while(~scanf("%d",&a[i].num)){
        int cnti = 0,numi = a[i].num;
        if(numi==0) {
            a[i].cnt = 1;
            i++;
            continue;
        }
        while(numi){
            numi/=10;
            cnti++;
        }
        a[i].cnt = cnti;
        i++;
    }
    qsort(a,i,sizeof(Int),cmp);
    for(int j = 0; j<i; j++){
        printf("%d ",a[j].num);
    }
    return 0;
}