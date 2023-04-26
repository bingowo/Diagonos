#include <stdio.h>
#define N 25

typedef struct { int cnt,v[N]; } BIGINT ;

BIGINT ADD(BIGINT a,BIGINT b)
{ int carry=0,j,t,cnt=a.cnt>b.cnt?a.cnt:b.cnt;
   BIGINT R;
   for (j=0;j<cnt;j++) { t=a.v[j]+b.v[j]+carry;  R.v[j]=t%10;  carry=t/10; }
   R.cnt=j;
   while (carry>0) { R.v[R.cnt++]=carry%10; carry/=10; }
  return R;
}
void printBIGINT(BIGINT R)
{  int i;
    for (i=R.cnt-1;i>=0;i--) printf("%d",R.v[i]);
}

int main()
{   int I,T;
     for(scanf("%d",&T),I=0;I<T;I++)
     {    int n,i; BIGINT a={1,{0}},b={1,{1}},c;
           printf("case #%d:\n",I);
           scanf("%d",&n);
           if (n>=1)  for (i=2;i<=n;i++)  c=ADD(a,b),a=b,b=c;
           else b=a;
           printBIGINT(b);  printf("\n");
     }
    return 0;
}