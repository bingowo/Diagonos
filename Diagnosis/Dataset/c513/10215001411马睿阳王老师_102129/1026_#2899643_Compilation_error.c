#include<stdio.h>
int s[10007];
int main()
{
  long long int n;
  long long int i;
  int t;
  
  scanf("%lld\n",&n);
  scanf("%d ",&s[0]);
  qsort(s,n,sizeof(s[0]),compare);
  
  long long int min=0;
  long long int j;
  for(i=0;i<n-4;i+2)
  {min+=s[i+1]-s[i];}
  printf("%lld",min);
  return 0;
}

int compare(int a,int b)
{if(a>b) return -1;
 else return 1;
}

