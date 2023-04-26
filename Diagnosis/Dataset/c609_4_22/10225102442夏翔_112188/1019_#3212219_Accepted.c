#include <stdio.h>
#include <stdlib.h>
int f(int a){
    int ret=0;
    if(a<0) a = a*-1;
    while(a!=0){
        ret++;
        a = a/10;
    }
    return ret;
}
int cmp1(const void *a, const void *b){
    int x1=*(int*)a, x2=*(int*)b;
    int n1=f(x1), n2=f(x2);
    if(n1!=n2) return n2-n1;
    else return x1-x2;
}
int main(){
    int *num, count=0, temp;
    num = (int*)calloc(1e+6,sizeof(int));
    while(scanf("%d", &temp)!=EOF){
        num[count++] = temp;
    }
    qsort(num,count,sizeof(num[0]),cmp1);
    for(int i=0; i<count-1; i++) printf("%d ", num[i]);
    printf("%d", num[count-1]);
    free(num);
    return 0;
}
