#include <stdio.h>
#include <stdlib.h>
int count(long long int num)
    {
        int count=0;
        int i=64;
        while (i--)
        {
            if (num&1==1)
            {
              count++;
            }
            num=num>>1;
        }
        return count;
    }
void Sort(long long int *p, int n)
{
    int mycomp(const void *p1,const void *p2)
    {
        int j=count(*(long long int*)p1);
        int k=count(*(long long int*)p2);
        if (j>k) return -1;
        if (j<k) return 1;
        else
        {
            if ((*(long long int*)p1)>(*(long long int*)p2)) return 1;
            if ((*(long long int*)p1)<(*(long long int*)p2)) return -1;
            else return 0;
        }
    }
    qsort(p,n,8,mycomp);
}
int main()
{
   int T,N;
   scanf("%d",&T);
   long long int num[10000];
   for(int i=0;i<T;i++)
   {
       scanf("%d",&N);
       for(int j=0;j<N;j++)
       {
           scanf("%lld",&num[j]);
       }
       Sort(num,N);
       printf("case #%d:\n",i);
       for(int k=0;k<N;k++) printf("%lld ",num[k]);
       printf("\n");
   }
}
