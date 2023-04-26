#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    int c = *(int*)a;int d = *(int*)b;
    int e =c,f = d;
    int t1 = 0,t2 = 0;
    if(c<0)
        c = -c;
    if(d<0)
        d = -d;
    if(c == 0)
        t1 = 1;
    if(d == 0)
        t2 = 1;
    while(c){
        c /= 10;
        t1++;
    }
    while(d){
        d /= 10;
        t2++;
    }
    if(t1 == t2){
        return e - f;
    }
    else
        return t2 - t1;

}
int main(){
    int in[1000001];
    int i = 0;
    while(scanf("%d",&in[i]) != EOF)
        i++;
    qsort(in,i,sizeof(int),cmp);
    for(int k = 0;k<i;k++)
        printf("%d ",in[k]);
    return 0;
}
