#include<stdio.h>
#include<string.h>
void cmp(long long int*s)
{long long int i=0,t,c;
 c=strlen(s);
 for(i=0;i<c;i++)
 {if(s[i]<s[i+1])
     {t=s[i];
      s[i]=s[i+1];
      s[i+1]=t;
     }
  }
}

int main()
{long long int m,n,i=0;
 long long int s[1000000000000];
 scanf("%lld %lld\n",&n,&m);
 for(i=0;i<n;i++)
 scanf("%lld ",&s[i]);
 long long int j=1;
 n=strlen(s);
 cmp(s);
 long long int sum=0,min;
 for(j=1;j<m;j++)
 {sum+=s[j];}
  min=s[0]-sum;
  printf("%lld",min);
  return 0;
}
