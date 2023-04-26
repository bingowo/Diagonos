#include<stdio.h>
int s[10007];
int main()
{
  long long int n;
  long long int i;
  int t;
  
  scanf("%lld\n",&n);
  scanf("%d ",s[0]);
  for(i=1;i<n;i++)
  {scanf("%d ",&s[i]);
   if(s[i]>s[i-1])
   { t=s[i];
     s[i]=s[i+1];
     s[i+1]=t;
   }
  }
  long long int min=0;
  long long int j;
  for(i=0;i<n-4;i+2)
  {min+=s[i+1]-s[i];}
  printf("%lld",min);
  return 0;
}


