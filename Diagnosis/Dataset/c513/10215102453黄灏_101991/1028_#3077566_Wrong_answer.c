#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b){
    int *x=a;int *y=b;
    return *x-*y;
}
int cmp2(const void *a,const void *b){
    int *x=a;int *y=b;
    return *y-*x;
}

int main()
{
    char c;
    scanf("%c",&c);
    int num[1000]={0};
    int i=0;
    while(scanf("%d",&num[i]) != EOF) i++;
    if(c=='A') qsort(num,i,sizeof(num[0]),cmp1);
    if(c=='D') qsort(num,i,sizeof(num[0]),cmp2);
    for(int j=0;j<i;j++){
        printf("%d ",num[j]);
    }
    return 0;
}
