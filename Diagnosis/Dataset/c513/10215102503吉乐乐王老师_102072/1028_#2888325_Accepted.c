#include<stdio.h>
#include<stdlib.h>
char order;
int cmp(const void *a,const void *b){
    int x=*(int *)a;
    int y=*(int *)b;
    if(order=='A')return x-y;
    return y-x;
}
int main(){
    scanf("%c\n",&order);
    int n[1000]={0};int idx=0;
    while(scanf("%d",&n[idx])==1){
        idx++;
    }
    qsort(n,idx,sizeof(int),cmp);
    for(int i=0;i<idx;i++){
        if(n[i]!=0){
            if(n[i]==n[i+1])continue;
            printf("%d",n[i]);
            if(n[i+1]==0)printf("\n");
            else printf(" ");
        }
    }
}