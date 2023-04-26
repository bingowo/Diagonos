#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{
    int B;           //记录数字
    int cnt;       //记录在A中的位置
} STRUCT;

int cmp(const void*a,const void *b){
    STRUCT* x=(STRUCT*)a;
    STRUCT* y=(STRUCT*)b;
    if((x->cnt)==(y->cnt)){ return (x->B-y->B);}
    else {return x->cnt-y->cnt;}

}

int main()
{
    int n,m,i,j;

    scanf("%d",&m);
    int A[m];
    for(i=0;i<m;i++){
        scanf("%d",&A[i]);
    }

    scanf("%d",&n);
    STRUCT sb[n];
    for(i=0;i<n;i++){
        scanf("%d",&sb[i].B);
    }

    for(i=0;i<n;i++){    //逐个检索 是否在A中 在的话记录A中坐标
        for(j=0;j<m;j++){
            if(A[j]==sb[i].B){sb[i].cnt=j; break;}
            else{sb[i].cnt=600;}
        }
    }
    qsort(sb,n,sizeof (STRUCT),cmp);
    for(i=0;i<n;i++){
        printf("%d ",sb[i].B);
    }

    return 0;
}
