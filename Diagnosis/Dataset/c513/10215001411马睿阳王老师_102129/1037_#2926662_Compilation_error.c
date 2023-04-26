#include<stdio.h>
#include<string.h>
 int compare(const void*a,const void*b)
{long long int s1=*(long long int *)a;
 long long int s2=*(long long int *)b;
 if(s1>s2) return -1;
 else return 1;
}

int main()
{long long int m,n,i=0;
 long long int s[1000000];
 scanf("%lld %lld",&n,&m);
 for(i=0;i<n;i++)
 scanf("%lld ",&s[i]);
 qsort(s,n,sizeof(long long int),compare);
 long long int min=0,sum=0,j=1;
 for(j=1;j<m;j++)
 {sum+=s[j];}
 d=(m-1)*s[i]-sum;
 for(i=0;i<n-m+1;i++)
 { min=0,sum=0,j=i+1;
  for(j=i+1;j<i+m;j++)
  {sum+=s[j];}
  min=(m-1)*s[i]-sum;
  if(min<d) d=min;
 }
 printf("%lld",d);
 return 0;
}
