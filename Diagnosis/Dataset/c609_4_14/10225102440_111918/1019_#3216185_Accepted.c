#include <stdio.h>
#include <stdlib.h>
int cmp(void* a,void* b){
    int m=*(int*)a,n=*(int*)b;
    if(f(m)!=f(n)) return f(n)-f(m);
    else if(m>=n) return 1;
    else return -1;
}
int f(int x){
    int n=0;
    if(x<0)x=-x;
    while(x) {
        n++;
        x=x/10;
    }
    return n;
}
int main()
{
    int j,i=0,x[1000000];
    while(scanf("%d",&x[i])!=EOF) i++;
    qsort(x,i,sizeof(x[0]),cmp);
    for(j=0;j<i;j++) printf("%d ",x[j]);
    return 0;
}
