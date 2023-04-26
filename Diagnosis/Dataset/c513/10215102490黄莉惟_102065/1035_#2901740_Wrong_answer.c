#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
    long long int r[1000];
    long long int h[1000];
} SELECT;

long long comp1(long long int *s1,long long int *s2){
    SELECT v1=*(SELECT*)s1;
    SELECT v2=*(SELECT*)s2;
    long long int sum1,sum2;
    sum1=(v1.r[0])*(v1.h[0])/2;
    sum2=(v2.r[0])*(v2.h[0])/2;
    if(sum1==sum2){
        return v1.r[0]< v2.r[0] ?1:-1;
    }else{
        return sum2-sum1;
    }
    
}
long long comp2(long long int *s1,long long int *s2){
    SELECT v1=*(SELECT*)s1;
    SELECT v2=*(SELECT*)s2;
    return v1.r[0]< v2.r[0]?1:-1;
}

/********** Specification of Input **********/
void Input(SELECT a[],int n)
{ 
   int i=0;
   while(n>0){
      scanf("%lld %lld",&a[i].r[0],&a[i].h[0]); 
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


int main() {
    int i,n,j,m;
    long long int sum=0;
    scanf("%d %d",&n,&m);
    SELECT a[n];
    Input(a,n);
    Sort1(a, n);
    Sort2(a, m);
    for (i = 0; i < m; i++){
        sum=sum+2*(a[i].r[0])*(a[i].h[0]);
    }
    sum=sum+(a[0].r[0])*(a[0].r[0]);
    long long int num;
    long long int min=(a[0].r[0])*(a[0].h[0]);
    for(j=0;j<m;j++){
            if(min>=(a[j].r[0])*(a[j].h[0])){
                min=(long long int)(a[j].r[0])*(long long int)(a[j].h[0]);
            }
        }
    //printf("%lld",min);
    long long int max=sum;
    for(i=m;i<n;i++){
        if(a[i].r[0]>a[0].r[0]){
            num=sum-2*min-(a[0].r[0])*(a[0].r[0])+(a[i].r[0])*(a[i].r[0])+2*(a[i].r[0])*(a[i].h[0]);
            if(num>max){
                max=num;
            }
        }
        //printf("%lld\n",num);
    }
    printf("%lld",max);
    return 0;
}  