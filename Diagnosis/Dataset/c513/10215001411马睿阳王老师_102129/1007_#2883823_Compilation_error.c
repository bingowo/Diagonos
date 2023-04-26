#include<stdio.h>
#include<math.h>
int main()
{int T,k=0,n;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {char s[1000];int i=0,c,x=0,t;
  scanf("%d",n);
  while(n)
  {c=n%2;
   s[i]=c+'0';
   i++;
   n=n/2;
  }
  for(x=0;x<i/2;x++)
  {t=s[x];s[x]=s[i-x];s[i-x]=t;}
  int j=1,count=1;
  while(s)
  {if(s[j-1]==0) j++;
   if(s[j]!=s[j-1]) count++;
        else break;}
   j++;
  }
  printf("case #%d:\n",k);
  printf("%d",count);
  }
  return 0;
}
