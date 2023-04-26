#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a[50];
    int nums;
} array;
int cmp(const void*a,const void*b)
{
    array *pa,*pb;
    pa = (array*)a;
    pb = (array*)b;
    printf("%d %d",pa->nums,pb->nums);
    int minor;
    if(pa->nums>pb->nums) minor = pb->nums;
    else minor = pa->nums;
    for(int i=0;i<minor;i++){
        if(pa->a[i] != pb->a[i]) return pa->a[i]-pb->a[i];
        else{
            if(i == minor-1) return pb->nums-pa->nums;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        array L[N];
        for(int j=0;j<N;j++){
            int tmp,cnt = 0;
            while(scanf("%d",&tmp)&&(tmp != -1)){
                L[j].a[cnt++] = tmp;
            }
            L[j].nums = cnt;
        }
        qsort(L,N,N*sizeof(array),cmp);
        for(int j=0;j<N;j++){
            for(int k=0;k<L[j].nums;k++){
                printf("%d%c",L[j].a[k],(k == L[j].nums-1)?'\n':' ');
            }
        }
    }

    return 0;
}
