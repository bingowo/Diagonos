#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 struct number {
            int num;//原数
            int numcopy;//用于求1的个数，不影响原数
            int count;//每个数字1的个数
        }*a;

int cmp(const void *a,const void *b){
    struct number *aa=(struct number *)a;
    struct number *bb=(struct number *)b;
    if((aa->count)!=(bb->count))
        return (((bb->count)>(aa->count))?1:-1);
    else
        return ((aa->num)-(bb->num));
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int N;//N个数字
        scanf("%d", &N);
        a = (struct number*)malloc(sizeof(struct number) * N);
        for(int i=0;i<N;i++){
            a[i].count=0;
        }//count初始化为0
        for(int i=0;i<N;i++){
            scanf("%d",&a[i].num);
            a[i].numcopy=a[i].num;
            while(a[i].numcopy){
                a[i].numcopy&=(a[i].numcopy-1);
                a[i].count++;
            }
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<N;i++){
            printf("%d ",a[i].num);
        }
        printf("\n");
    }
    return 0;
}
