#include <stdio.h>
#include <stdlib.h>
typedef struct{
long long a;
int b;
}Num;
int f(long long n)
{
    int count=0,sign=0,a;
    if(n<0){
        n=-n-1;
        sign=1;
    }
    do{
        a=n%2;
        n/=2;
        if(a==1) count++;
    }while(n!=0);
    if(sign) return 64-count;
    return count;
}
int cmp(const void *a, const void *b) {
 Num *A = (Num *)a;
 Num *B = (Num *)b;
 if (A->b == B->b) {
  if (A->a > B->a)
   return 1;
  else
   return -1;
 } else {
  if (A->b > B->b)
   return -1;
  else
   return 1;
 }
}
int main()
{
    int T;scanf("%d",&T);
    long long mi;
    for(int i=0;i<T;i++)
    {

        int N;scanf("%d",&N);
        Num nums[10001];
        for(int j=0;j<N;j++)
            {scanf("%lld",&nums[j].a);
            long long tmp=nums[j].a;
            nums[j].b=f(nums[j].a);}
        qsort(nums,N,sizeof(nums[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
            printf("%lld ",nums[j].a);
        printf("\n");
    }

    return 0;
}
