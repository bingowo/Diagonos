#include <stdio.h>
#include <stdlib.h>
int cmp(long long *a,long long*b)
{if(*a>*b) return 1;
else return -1;}
int main()
{long long int n,temp=0;
scanf("%lld",&n);
long long*a=(long long *)malloc(n*sizeof(long long));
for(long long int i=0;i<n;i++)
{scanf("%lld",&a[i]);

}
qsort(a,n,sizeof(a[0]),cmp);
for(int j=0;j<n-1;j+=2)
{temp+=(a[j+1]-a[j]);
}
printf("%lld",temp);
    free(a);
}
