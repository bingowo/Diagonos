#include<stdio.h>
int main()
{
    int T,i,k;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {char s[61];
    scanf("%s\n",&s);
    int a[128];
    for(k=0;k<128;k++)
    a[k]=-1;
    char *p;
    p=s;
    a[*p]=1;
    int N=1,digit=0;
    p++;
    while (*p)
    {
        if (a[*p]==-1)   
     { a[*p]=digit; digit=digit?digit+1:2; N++;}
     p++;
    }
  if (N<2) N=2;
  p=s;
  long long int data=0;
  while(*p)
  {data=data*N+a[*p++];}
  printf("case #%d:\n",i);
  printf("%lld\n",data);
    }
    return 0;
}

