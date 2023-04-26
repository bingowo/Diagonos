#include <stdio.h>
#include <stdlib.h>
int cmp1(void* a,void* b){
    int m=*(int*)a,n=*(int*)b;
    return m-n;
}
int cmp2(void* a,void* b){
    int m=*(int*)a,n=*(int*)b;
    return n-m;
}
int main()
{
    char a;
    scanf("%c",&a);
    int x[100],i=0,j,b=0;
    while(scanf("%d",&x[i])!=EOF)i++;
    if(a=='A') qsort(x,i,sizeof(x[0]),cmp1);
    else qsort(x,i,sizeof(x[0]),cmp2);
    for(j=0;j<i-1;j++){
        if(x[j]!=b) printf("%d ",x[j]);
        b=x[j];
    }
    if(x[j]!=b)printf("%d",x[j]);
    return 0;
}
