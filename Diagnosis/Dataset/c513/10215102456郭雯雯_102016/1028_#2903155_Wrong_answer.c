#include<stdio.h>
#include<stdlib.h>
int cmp1(int a,int b){
    if(a>b)return 1;
    if(a<b)return -1;
    return 0;
}
int cmp2(int a,int b){
    if(a>b)return -1;
    if(a<b)return 1;
    return 0;
}
int main(){
    char w;
    scanf("%c",&w);
    int L[100],n,i=0;
    while(scanf("%d",&n)!=EOF){
        L[i]=n;
        i++;
    }
    if(w=='A')qsort(L,i,sizeof(int),cmp1);
    if(w=='D')qsort(L,i,sizeof(int),cmp2);
    for(int j=1;j<i;j++)
        if(L[j]!=L[j-1])printf("%d ",L[j-1]);
    printf("%d",L[i-1]);
    return 0;
}
