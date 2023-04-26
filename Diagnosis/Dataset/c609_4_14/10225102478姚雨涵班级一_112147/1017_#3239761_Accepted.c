#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp1(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
int cmp2(const void *a,const void *b){
    return *(int*)b - *(int*)a;
}
int main(){
    char a;
    scanf("%c",&a);
    int in[101];
    int i=0;
    while(scanf("%d",&in[i]) != EOF)
        i++;
    if(a =='A'){
        qsort(in,i,sizeof(int),cmp1);
    }
    else{
        qsort(in,i,sizeof(int),cmp2);
    }
       for(int k = 0;k<i;k++){
        if(k>0 && in[k] == in[k-1])
        continue;
        printf("%d ",in[k]);
       }
    return 0;
}
