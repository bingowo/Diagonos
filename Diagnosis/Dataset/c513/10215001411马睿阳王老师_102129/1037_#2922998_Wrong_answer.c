#include<stdio.h>
#include<string.h>
void cmp(long long int*s)
{ long long int i=0,t,c;
 c=strlen(s);
 for(i=0;i<c-1;i++)
 {if(s[i]<s[i+1])
     {t=s[i];
      s[i]=s[i+1];
      s[i+1]=t;
     }
  }
}

int main()
{long long int m,n,i=0;
 long long int s[10000];
 n=strlen(s);
 scanf("%lld %lld",&n,&m);
 scanf("%lld ",s);
 long long int j=1;
 cmp(s);
  long long int sum=0,min;
 for(j=1;j<m;j++)
 {sum+=s[j];}
  min=(m-1)*s[0]-sum;
  printf("%lld",min);
  return 0;
}
