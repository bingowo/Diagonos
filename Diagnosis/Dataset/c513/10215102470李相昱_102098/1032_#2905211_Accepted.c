#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int num[51];
}number;
int cmp(const void *p1,const void  *p2){
    int i=0;
    do {
        if(((number*)p1)->num[i] < ((number*)p2)->num[i]){
            return 1;
        }else if(((number*)p1)->num[i] > ((number*)p2)->num[i]) {
            return -1;
        }
        i++;
    }while ((((number*)p1)->num[i])&&(((number*)p2)->num[i]));
    if(((number*)p1)->num[i]){
        return 1;
    }else
        return -1;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        number a[N];
        int j =0;
        int i =0;
        int N1 = N;
        while (N1--){
            do{
                scanf("%d",&a[i].num[j++]);
            }while (a[i].num[j-1]!=-1);
            i++;
            j = 0;
        }
        qsort(a,N,sizeof(number),cmp);
        for(int p = 0;p<N;p++){
            for(int m=0;a[p].num[m]!=-1;m++){
                printf("%d%c",a[p].num[m],a[p].num[m+1]==-1?'\n':' ');
            }

        }
    }
    return 0;
}