#include<stdio.h>
int s[10007];
int compare(const void* a,const void* b);
int main()
{
  long long int n;
  long long int i;
  int t;

  scanf("%lld\n",&n);
  scanf("%d ",&s[0]);
  qsort(s,n,sizeof(int),compare);

  long long int min=0;
  long long int j;
  for(i=0;i<n-4;i+2)
  {min+=s[i+1]-s[i];}
  printf("%lld",min);
  return 0;
}

int compare(const void* a,const void* b)
{int n1=*(int *a);
 int n2=*(int *b);
 return(n1-n2);
}

