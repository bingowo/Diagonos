#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct fen{
    int up;
    int down;
};
 int gcd( int m, int n)
{
     int temp;
    if(m<n) temp=m,m=n,n=temp;     //m中放较大数
    if(m%n==0) return n;
    temp=n,n=m%n,m=temp;
    return(gcd(m,n));
}
int main()
{ int i,j,n,m,l,f,tmp;
  struct fen a[110];
  char s[50];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  { scanf("%s",s);
    l=strlen(s);
    a[i].up=0; a[i].down=0;
    for(j=0;s[j]!='/';j++)
    {
        a[i].up=a[i].up*10+s[j]-'0';
    }
    j++;
    for(j;j<l;j++)
    {
        a[i].down=a[i].down*10+s[j]-'0';
    }
  }
  m=a[0].down;
  for(i=1;i<n;i++)
  { m=m*a[i].down/gcd(m,a[i].down);
  }
  f=0;
  for(i=0;i<n;i++)
  { f+=a[i].up*m/a[i].down;
  }
  tmp=gcd(m,f);
  printf("%d/%d",f/tmp,m/tmp);
}