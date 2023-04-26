#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int num;//编号
    int sco;
    int win;//胜场
    int los;//负场
}T;
static int cmp(const void* a, const void* b){
    T x = *((T*)a);
    T y = *((T*)b);
    if(x.sco == y.sco){
        if(x.win == y.win){
            if(x.los == y.los){
                return x.num - y.num;
            }
            return x.los - y.los;
        }
        return y.win - x.win;
    }
    return y.sco - x.sco;
}
int main(){
    int n, m, a, b, c;
    while(1){
        scanf("%d %d", &n, &m);
        if(n==0 && m==0){
            break;
        }
        T* array = (T*)malloc(sizeof(T)*n);
        for(int i = 0; i<n; i++){
            array[i].num = i+1;
            array[i].sco = 0;
            array[i].los = 0;
            array[i].win = 0;
        }
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            if(c==1){
                array[a-1].sco += 3;
                array[a-1].win ++;
                array[b-1].sco -= 1;
                array[b-1].los ++;
            }
            else if(c==-1){
                array[b-1].sco += 3;
                array[b-1].los ++;
                array[a-1].sco -= 1;
                array[a-1].los ++;
            }
            else{
                array[b-1].sco += 1;
                array[a-1].sco += 1;
            }
        }
        qsort(array, n, sizeof(T), cmp);
        for(int i = 0; i<n; i++){
            printf("%d", array[i].num);
            if(i<n-1){
                printf(" ");
            }
        }
        printf("\n");
        free(array);
    }
    return 0;
}