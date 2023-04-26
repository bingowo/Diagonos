#include <stdio.h>
#include <stdlib.h>

int cmp(const void *q1,const void *q2){
    long long *p1 = (long long *)q1;
    long long *p2 = (long long *)q2;
    return *p1-*p2;
}

int main() {
    int total;
    scanf("%d",&total);
    long long *point = (int*) malloc(total*sizeof(long long ));
    for(int i=0;i<total;i++){
        scanf("%lld",point[i]);
    }
    qsort(point,total,sizeof(long long),cmp);
    long long sum=0;
    for(int i=0;i<total/2;i++){
        sum += point[2*i+1]-point[2*i];
    }
    printf("%lld",sum);
    return 0;
    free(p);
}
