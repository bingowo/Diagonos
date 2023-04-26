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
    if(x.sco != y.sco){
        return y.sco - x.sco;
    }
    if(x.win != y.win){
        return y.win - x.win;
    }
    if(x.los != y.los){
        return x.los - y.los;
    }
    return x.num - y.num;
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
                array[b-1].win ++;
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
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int* row;
    int len;
}R;
static int cmp(const void* a, const void* b){
    R x = *((R*)a);
    R y = *((R*)b);
    int len = (x.len<y.len)? x.len:y.len;
    for(int i = 0; i<len; i++){
        if(x.row[i] == y.row[i]){
            continue;
        }
        return y.row[i] - x.row[i];
    }
    return y.len - x.len;
}
int main(){
    int T, N, cnt, x, temp[500];
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
        cnt = 0;
        scanf("%d", &N);
        (R*) l = (R*)malloc(sizeof(R)*N);//装下N行
        for(int j = 0; j<N; j++){//N行的输入
            while(1){
                scanf("%d", &x);
                if(x==-1){break;}
                else{
                    temp[cnt++] = x;
                }
           }
           l[j].row = (int*)malloc(sizeof(cnt)*int);
           l[j].len = cnt;
           for(int k = 0; k<cnt; k++){
                l[k].row[k] = temp[k];
           }
        }
        qsort(l, N, sizeof(R), cmp);
        for(int j = 0; j<N; j++){
            for(int k = 0; k<)
        }
    }

    return 0;
}
*/