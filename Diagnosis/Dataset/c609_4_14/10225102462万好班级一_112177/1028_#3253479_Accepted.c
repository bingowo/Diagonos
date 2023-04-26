#include<stdio.h>
#include<stdlib.h>

typedef struct a
{long long six[51];} AR;



int suc_cmp(const void* a,const void*b){
    AR* p1 = (AR*)a;
    AR* p2 = (AR*)b;int i = 0;
    while(p1->six[i] == p2->six[i])i++;
    return (int)(p2->six[i] - p1->six[i]);
}

int main() {
    int big_loop;scanf("%d",&big_loop);
    for (int g = 0; g < big_loop; ++g) {
        int loop;
        scanf("%d", &loop);

        AR array[loop];
        for (int j = 0; j < loop; ++j) {
            long long int q[51];
            for (int i = 0;; i++) {
                scanf("%lld", &q[i]);
                array[j].six[i] = q[i];
                if (q[i] == -1) {
                    array[j].six[i] = q[i] = 0;
                    break;
                }
            }
        }
        qsort(array,loop,sizeof(AR),suc_cmp);
        for (int i = 0; i < loop; ++i) {
            for (int j = 0;array[i].six[j]; ++j) {
                printf("%lld ",array[i].six[j]);
            }printf("\n");
        }
    }
}