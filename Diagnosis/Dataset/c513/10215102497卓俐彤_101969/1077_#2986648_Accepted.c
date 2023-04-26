#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int value[501];
int cmp(const void*a,const void*b){
    int d1,d2;
    d1=*((int*)a);
    d2=*((int*)b);
    if(value[d1]&&value[d2])return value[d1]-value[d2];
    else if(value[d1])return -1;
    else if(value[d2])return 1;
    else return d1-d2;
}
int main(){
    int len1,len2;
    scanf("%d",&len1);
    int A[len1];
    for(int i=0;i<len1;i++){
        scanf("%d",&A[i]);
        value[A[i]]=i+1;
    }
    scanf("%d",&len2);
    int B[len2];
    for(int i=0;i<len2;i++)
        scanf("%d",&B[i]);
    qsort(B,len2,sizeof(B[0]),cmp);
    for(int i=0;i<len2;i++)
        printf("%d%c",B[i],i==len2-1?'\n':' ');
    return 0;
}

