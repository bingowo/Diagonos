#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
    int r[1000];
    int h[1000];
} SELECT;

long long comp1(int *s1,int *s2){
    SELECT v1=*(SELECT*)s1;
    SELECT v2=*(SELECT*)s2;
    int sum1,sum2;
    sum1=2*(v1.r[0])*(v1.r[0])+2*(v1.r[0])*(v1.h[0]);
    sum2=2*(v2.r[0])*(v2.r[0])+2*(v2.r[0])*(v2.h[0]);
    if(sum1==sum2){
        return v1.r< v2.r ?1:-1;
    }else{
        return sum2-sum1;
    }
    
}
long long comp2(int *s1,int *s2){
    SELECT v1=*(SELECT*)s1;
    SELECT v2=*(SELECT*)s2;
    return v1.r< v2.r ?1:-1;
}

/********** Specification of Input **********/
void Input(SELECT a[],int n)
{ 
   int i=0;
   while(n>0){
      int num;
      scanf("%d %d",&a[i].r[0],&a[i].h[0]); 
      i++;
      n--;
       
    }
    
    
}

/********** Specification of Sort **********/
void Sort1(SELECT *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp1);
}
void Sort2(SELECT *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp2);
}

#include <stdio.h>
#define N 100000

int main() {
    int i,n,t,j,m;
    long long int sum=0;
    scanf("%d %d",&n,&m);
    SELECT a[n];
    Input(a,n);
    Sort1(a, n);
    Sort2(a, m);
    for (i = 0; i < m; i++){
        sum=2*(a[i].r)*(a[i].h)+(a[i].r)*(a[i].r);
    }
    sum=sum-(a[m].r)*(a[m].r);
    printf("%lld",sum);
    return 0;

    
}  
