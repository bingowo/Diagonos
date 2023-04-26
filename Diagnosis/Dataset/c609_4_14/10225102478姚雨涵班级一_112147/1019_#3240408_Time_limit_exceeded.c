#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int com(int a){
    int temp;
    temp = 0;
    while(a != 0){
        a %= 10;
        temp++;
    }
    return temp;
}
int cmp(const void *a,const void *b){
    int c = *(int*)a;int d = *(int*)b;
    int t1,t2;
    t1 = com(c);t2 = com(d);
    if(t1 == t2){
        return *(int*)a - *(int*)b;
    }
    else
        return t2 - t1;

}
int main(){
    int in[100001];
    int i = 0;
    while(scanf("%d",&in[i]) != EOF)
        i++;
    qsort(in,i,sizeof(int),cmp);
    for(int k = 0;k<i;k++)
        printf("%d ",in[k]);
    return 0;
}
