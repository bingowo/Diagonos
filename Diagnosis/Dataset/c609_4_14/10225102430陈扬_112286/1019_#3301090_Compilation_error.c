#include <stdio.h>
#include <stdlib.h>
int n(int a){
    int ret=0;
    if(a<0){ 
        a = a*(-1);
        ret++;
    while(a!=0){
        ret++;
        a = a/10;
    }
    return ret;
}
int cmp(const void *a, const void *b){
    int x1=*(int*)a, x2=*(int*)b;
    int n1=n(x1), n2=n(x2);
    if(n1!=n2) return n2-n1;
    else return (x1-x2);
}
int main(){
    int *num, count=0, temp;
    num = (int*)calloc(1e+6,sizeof(int));
    while(scanf("%d", &temp)!=EOF){
        num[count++] = temp;
    }
    qsort(num,count,sizeof(num[0]),cmp);
    for(int i=0; i<=count-1; i++) printf("%d ", num[i]);
    free(num);
    return 0;
}