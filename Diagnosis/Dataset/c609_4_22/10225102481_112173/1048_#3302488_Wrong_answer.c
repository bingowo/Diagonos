#include <stdio.h>
#include <stdlib.h>

#define N 500

 void full(int n1[N],int n2[N])
{
    for(int i=0;i<500;i++)
    {
        n1[i]=n2[i];
    }
}

int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       int n;
       scanf("%d\n",&n);

       int t1[N]={0};
       int t2[N]={0};
       int sum[N]={0};
       int temp[N]={0};
       t1[0]=t2[0]=1;
       for(int i=2;i<n;i++)
       {
           for(int k=0;k<N;++k)
           {
               sum[k]+=t1[k]+t2[k];
               if(sum[k]>9)
               {
                   sum[k+1]++;
                   sum[k]-=10;
               }
           }
           full(t1,t2);
           full(t2,sum);
           full(sum,temp);
       }
       for(int i=N-1;i>=0;i--)
       {
           if(t2[i]!=0)
           {
               printf("case #%d:\n",i);
               for(int k=i;k>=0;k--)printf("%d",t2[k]);
               printf("\n");
               break;
           }
       }



   }
   return 0;
}
