#include <stdio.h>
typedef unsigned long long int llu;

llu map[101] = {0};

void first_k(int k)
{
    map[1]=(llu)0; map[2]=(llu)1;
    llu sum=map[1] + map[2];
    for(int i=3; i<=k; i++)//给前k位赋值
    {
        map[i] = sum;
        sum = sum +map[i];
    }
    return ;
}

llu compute(int k, int n)
{
   llu ret;
   if(n<=k || map[n]!=0) ret = map[n];
   else
   {
       llu sum=0;
       for(int i=1; i<=k; i++)
       {
           sum=sum+compute(k,n-i);
       }
       map[n] =sum;
       ret=sum;
   }
   return ret;
}

int main()
{
    int k,n;
    scanf("%d %d",&k, &n);
    first_k(k);
    llu res = compute(k, n);
    printf("%llu\n", res);
    return 0;
    
}