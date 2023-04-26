#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p1,const void*p2){
    return *(int*)p1-*(int*)p2;
}
int main(){
    int a;
    int b;
    scanf("%d",&a);
    int A[a];
    for(int i=0;i<a;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&b);
    int B[b];
    for(int i=0;i<b;i++){
        scanf("%d",&B[i]);
    }
    int k,flag[b],C[b];//flag记录在B中不在A中的元素个数
    for(int i=0;i<b;i++){flag[i]=0;}
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
           if(B[j]==A[i]){printf("%d ",A[i]);flag[j]=1;}
        }
    }
    for(int i=0;i<b;i++){
        if(flag[i]!=1)C[k++]=B[i];
    }
    //C放B中不在A中的元素
    qsort(C,k,sizeof(int),cmp);
    for(int i=0;i<k;i++){
        printf("%d ",C[i]);
    }
    return 0;
}
