#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void sort(long long int*s,int m)
{
    int cmp(const void*a,const void*b)
    {
       long long int i,j;
       i=*(long long int*)a;
       j=*(long long int*)b;
       while(i/10) i/=10;
       while(j/10) j/=10;
       if(i<0) i=-i;
       if(j<0) j=-j;
      if(i<j) return 1;
      if(i>j) return -1;
      if(i==j)
      {if(a<b) return -1;
      if(a>b) return 1;}
    }
    qsort(s,m,sizeof(s[0]),cmp);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        long long int a[10001];
        for(int k=0;k<m;k++)
        {
            scanf("%lld",&a[k]);
        }
        sort(a,m);
        printf("case #%d:\n",i);
        for(int l=0;l<m;l++)
        printf("%lld ",a[l]);
        printf("\n");
    }
    return 0;
}