#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int cmp(const void*p1,const void*p2)
{
     long long*p_1 = (long long*)p1;
     long long*p_2 = (long long*)p2;
     if(labs(p_1[0])+labs(p_1[1]) < labs(p_2[0])+labs(p_2[1])return1;
     else if(labs(p_1[0])+labs(p_1[1]) == labs(p_2[0])+labs(p_2[1]))
     {
         if(p_1[0]>p_2[0])return 1;
         else if(p_1[0] == p_2[0])
         {
             return (p_1[1]<p_2[1])?-1:1;
         }
         else return -1;
     }
     else return -1;
}
int main()
{

    int n;
    scanf("%d",&n);
    int i;
    long long p[200][2]
    for( i = 0;i< n;i++)
    {
        scanf("%lld%lld",&p[i][0],&p[i][1]);
    }
    qsort(p,n,sizeof(long long)*2,cmp);

    return 0;
}
