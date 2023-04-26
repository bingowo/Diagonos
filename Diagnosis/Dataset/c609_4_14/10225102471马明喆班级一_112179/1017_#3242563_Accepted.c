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
    int pre;
    while(scanf("%d",&s[i])!=EOF) 
        i++;
    //i--;
    if(a=='A')
        qsort(s,i,sizeof(s[0]),cmp1);
    else
        qsort(s,i,sizeof(s[0]),cmp2);
    i--;
    printf("%d",s[0]);
    pre=s[0];
    for(int x=1;x<i+1;x++){
        if(s[x]!=pre){
        printf(" %d",s[x]);
        pre=s[x];
        }
    }
    printf("\n");
    return 0;
}