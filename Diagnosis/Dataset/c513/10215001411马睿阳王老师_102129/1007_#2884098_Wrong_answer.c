#include<stdio.h>
#include<math.h>
int main()
{int T,k=0,n;int count=1;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {char s[1000];int i=0,c,x=0,t;
  scanf("%d",&n);
  while(n)
  {c=n%2;
   s[i]=c+'0';
   i++;
   n=n/2;
  }
  for(x=0;x<i/2;x++)
  {t=s[x];s[x]=s[i-x];s[i-x]=t;}
  int j=1;
  char*p=s;
  while(*p)
  {if(s[*--p]==0) j++;
   if(s[*p]!=s[*--p]) count++;
        else break;}
   j++;
  printf("case #%d:\n",k);
  printf("%d\n",count);}
  return 0;
}
