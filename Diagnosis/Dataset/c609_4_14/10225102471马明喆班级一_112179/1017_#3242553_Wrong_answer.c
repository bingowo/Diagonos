#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a , const void *b){
    return *(int *)a - *(int *)b;
}

int cmp2(const void *a , const void *b){
    return *(int *)b-*(int *)a;
}

int main(){
    char a;
    scanf("%c",&a);
    int s[10000];
    int i=0;
    int pre=-1;
    while(scanf("%d",&s[i])!=EOF) 
        i++;
    if(a=='A')
        qsort(s,sizeof(s[0]),i,cmp1);
    else
        qsort(s,sizeof(s[0]),i,cmp2);
    i--;
    printf("%d",s[0]);
    for(int x=1;x<i+1;x++){
        if(s[x]!=pre){
        printf(" %d",s[x]);
        pre=s[x];
        }
    }
    printf("\n");
    return 0;
}