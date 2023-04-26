#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_A[1001];
int cmp1(const void *a,const void *b);
int cmp2(const void *a,const void *b);
int main()
{
   int a,b,mid,i;
   scanf("%d",&a);
   for(i=0;i<a;i++)
   {
       scanf("%d",&mid);
       num_A[mid]=i+1;
   }
   int B[501];
   scanf("%d",&b);
   for(i=0;i<b;i++){scanf("%d",&B[i]);}
   //for(i=0;i<b;i++){printf("%d",B[i]);}
   int res1[501],res2[501];
   int cnt1=0,cnt2=0;
   for(i=0;i<b;i++)
   {
       if(num_A[B[i]]!=0){res1[cnt1++]=B[i];}
       else {res2[cnt2++]=B[i];}
   }
    qsort(res1,cnt1,sizeof(res1[0]),cmp1);
    qsort(res2,cnt2,sizeof(res2[0]),cmp2);
    //for(i=0;i<cnt1;i++){printf("%d",res1[i]);}
    //printf("\n");
    //for(i=0;i<cnt2;i++){printf("%d",res2[i]);}
    if(cnt1==0)
    {
        printf("%d",res2[0]);
        for(i=1;i<cnt2;i++){printf(" %d",res2[i]);}
    }
    else
    {
        printf("%d",res1[0]);
        if(cnt1>1){for(i=1;i<cnt1;i++){printf(" %d",res1[i]);}}
        for(i=0;i<cnt2;i++){printf(" %d",res2[i]);}
    }
    return 0;
}
int cmp1(const void *a,const void *b)
{
    if(num_A[*(int *)a]>num_A[*(int *)b])return 1;
    else if(num_A[*(int *)a]<num_A[*(int *)b])return -1;
    else return 0;
}
int cmp2(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
