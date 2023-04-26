#include<stdio.h>
#include<stdlib.h>

int cmp(const void *q1,const void *q2)
{
    long long *p1=(long long*)q1;
    long long *p2=(long long*)q2;
    if(*p1>*p2)
    return 1;
    else return -1;
}

int main()
{
      int n;
      scanf("%d",&n);
      long long s[n];
      for(int i=0;i<n;i++)
        scanf("%lld",&s[i]);
      qsort(s,n,sizeof(long long),cmp);
      long long min=0;
      for(int i=0;i<n/2;i++)
        min+=s[2*i+1]-s[2*i];
      printf("%lld",min);
    return 0;
}

