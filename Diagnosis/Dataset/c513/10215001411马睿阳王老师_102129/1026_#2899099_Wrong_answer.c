#include<stdio.h>
int main()
{
  long long int n;
  long long int i;
  int t;
  char s[10000];
  scanf("%lld\n",&n);
  scanf("%c ",s[0]);
  for(i=1;i<n;i++)
  {scanf("%c ",&s[i]);
   if(s[i]>s[i-1])
   { t=s[i];
     s[i]=s[i+1];
     s[i+1]=t;
   }
  }
  long long int min=0;
  long long int j;
  for(j=0;j<n-4;j+2)
  {min+=s[j+1]-s[j];}
  printf("%lld",min);
  return 0;
}


