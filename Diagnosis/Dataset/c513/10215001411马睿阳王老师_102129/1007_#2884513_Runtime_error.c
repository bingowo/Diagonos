#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{int T,k=0,n;int count=1,y=1,h,d;
 d=strlen(h);
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
  i--;
  for(x=0;x<i/2;x++)
  {t=s[x];s[x]=s[i-x];s[i-x]=t;}
  s[i+1]='\0';
  int j=1;
  s[d]=s[d-1];
  while(j<strlen(s))
  {if(s[j]!=s[j-1]) count++;
   else if(y>=count) {y=count;count=1;}
   else if(y<count) k=1;
  }
   j++;
  printf("case #%d:\n",k);
  printf("%d\n",y);
  for(h=0;h<d;h++)
  s[h]='\0';
 }
  return 0;
}
