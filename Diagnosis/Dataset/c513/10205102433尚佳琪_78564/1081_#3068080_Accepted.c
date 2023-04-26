#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100
void mul(int *result,int a)//数组(大整数)*整数
{
    int i,carry=0;
    for (i=0; i<N; i++)
    {
        int t=result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;

    }
}
int main()
{
   int t;
   scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
       int a,n,j,k,m,result[100]={0};
       scanf("%d %d",&a,&n);
       result[0]=1;
       if(n!=0){
       for( j=0;j<n;j++)
           mul(result,a);
        int l=94;
        while(result[l]==0)
            l=l-1;//去掉前置0
        printf("case #%d:\n",i);
       for(k=l;k>=0;k--)
          printf("%d",result[k]);
        printf("\n");
       }
       else printf("case #%d:\n1\n",i);
    }
}