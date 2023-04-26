#include <stdio.h>
#define N 25
typedef struct { int cnt,v[N]; } BIGINT ;

BIGINT ADD(BIGINT a,BIGINT b)
{ int carry=0,j,t,cnt=a.cnt>b.cnt?a.cnt:b.cnt;
   BIGINT R;
   for (j=0;j<cnt;j++)
    { t=(j<a.cnt?a.v[j]:0)+(j<b.cnt?b.v[j]:0)+carry;  R.v[j]=t%10;  carry=t/10; }
   R.cnt=j; while (carry>0) { R.v[R.cnt++]=carry%10; carry/=10; }
  return R;
}
void printBIGINT(BIGINT R)
{  int i; for (i=R.cnt-1;i>=0;i--) printf("%d",R.v[i]);  }

int main()
{ int I,T;
  for(scanf("%d",&T),I=0;I<T;I++)
  {  int n; BIGINT a={1,{0}},b={1,{1}},c;
     printf("case #%d:\n",I);
     if ((scanf("%d",&n),n)>=1)  for (i=2;i<=n;i++)  c=ADD(a,b),a=b,b=c;
     else b=a;
     printBIGINT(b);  printf("\n");
  }
  return 0;
}
