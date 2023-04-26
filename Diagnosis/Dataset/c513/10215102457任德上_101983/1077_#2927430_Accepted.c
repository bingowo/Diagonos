#include<stdio.h>
#include<stdlib.h>
int n1[1001]={0};
int cmp(const void *a,const void *b){
    int m1,m2;
    m1=*(int*)a;
    m2=*(int*)b;
    if(n1[m1]==0&&n1[m2]!=0)return 1;
    if(n1[m2]==0&&n1[m1]!=0)return -1;
    if(n1[m1]==0&&n1[m2]==0)return m1-m2;
    if(n1[m1]!=0&&n1[m2]!=0)return n1[m1]-n1[m2];
}

int main(){
    int n,m,n2[500];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        n1[m]=i+1;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&n2[i]);
    }
    qsort(n2,m,sizeof(int),cmp);
    for(int i=0;i<m;i++)printf("%d ",n2[i]);
    return 0;
}





