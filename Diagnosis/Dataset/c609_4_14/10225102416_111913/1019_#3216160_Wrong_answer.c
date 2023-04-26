#include<stdio.h>
#include<stdlib.h>

typedef struct NUM{
    int x;
}num;
int count(int a);
int cmp(const void *a,const void *b);
int main()
{
    num a[100];
    int i=0,m;
    while(scanf("%d",&a[i])!=EOF) i++;
    qsort(a,i,sizeof(a[0].x),cmp);
    for(m=0;m<i;m++){
        printf("%d ",a[m].x);
    }
    return 0;
}
int count(int a){
    int sum = 0;
    if(a<0){
        a = -a;
        sum = 1;
    }
    while(a){
        a = a/10;
        sum = sum+1;
    }
    return sum;
}
int cmp(const void *a,const void *b){
    int sum_a,sum_b;
    sum_a = count(* (int *)a);
    sum_b = count(* (int *)b);
    if(sum_a != sum_b){
        return sum_b-sum_a;
    }
    else{
        if(* (int *)a>* (int *)b) return 1;
        else return -1;
    }
}
