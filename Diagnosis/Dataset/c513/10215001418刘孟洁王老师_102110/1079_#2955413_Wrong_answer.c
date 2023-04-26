#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    long long int c = *(long long int*)a;
    long long int d = *(long long int*)b;
    if(c < d)return -1;
    else return 1;
}
long long int ss[1000007];
int main()
{
   int cas,n,m,i,j,k,l,h,len;
   long long int sum,ssum;
   long long int s[1007],L[1007],U[1007];
   scanf("%d",&cas);
 for(i = 0; i < cas; i++)
   {
       scanf("%d%d",&n,&m);
       for(j = 0; j < n; j++)scanf("%lld",&s[j]);
       ssum = n*(n+1)/2;
       for(j = 0; j < ssum; j++)ss[j] = 0;
       for(j = 0; j < m; j++)
       {
           L[j] = 0;U[j] = 0;
       }
        for(j = 0; j < m; j++)scanf("%lld%lld",&L[j],&U[j]);
       for(len = 1,k = 0; len <= n; len ++)
          for(j = 0; j < n; j++)
             {
                 for(l = 1,h = j,ss[k] = 0; l <= len; l++,h++)
                {
                   ss[k] += s[h];
                   if(l == len)k++;
                 }
                 if((n-j+1) < len)break;
             }
       qsort(ss,k,sizeof(ss[0]),cmp);
       printf("case #%d:\n",i);
      for(k = 0;k < m; k++)
        {
               for(j = L[k]-1,sum = 0; j < U[k]; j++)
           {
               sum += ss[j];
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}

