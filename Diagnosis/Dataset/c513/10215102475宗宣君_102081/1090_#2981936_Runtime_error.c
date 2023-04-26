#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
int cnt;
int v[100];
}BIG;
BIG bigint(int a)
{
    BIG A;
    A.cnt = 0;
    do{
        A.v[A.cnt++] = a%10;
        a/=10;
    }while(a!=0);
    return A;
}
BIG mul(BIG a,BIG b)
{
   int t,carry = 0,i,j;
   BIG R = {a.cnt+b.cnt,{0}};
   for(i = 0;i<a.cnt;i++)
   {
       carry = 0;
       for(j = 0;j<b.cnt;j++)
       {
           t = a.v[i]*b.v[j] + carry + R.v[i+j];
           R.v[i+j] = t%10;
           carry = t/10;
       }
       int k = i+j;
       while(carry>0)
       {
           t = R.v[k] + carry;
           R.v[k] = t%10;
           carry = t/10;
           k++;
       }
   }
   if(R.v[a.cnt+b.cnt-1]==0) R.cnt--;
   return R;

}
int main()
{

    while(1)
    {
        int n,i;
        scanf("%d",&n);
        if(n==0) break;
        else
        {
            BIG A = bigint(n),res = mul(A,A);
            //printf("%d\n",A.cnt);
            for(i = 2;i<n;i++)
            {
                res = mul(res,A);
            }
            printf("%d\n",res.v[res.cnt-1]);
        }
    }
    return 0;
}
