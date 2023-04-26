#include <stdio.h>
#include <stdlib.h>
int cmp(long long *a,long long*b)
{if(*a>*b) return 1;else return -1;}
int main()
{long long int n,max,temp;
scanf("%lld",&n);
long long*a=(long long *)malloc(n*sizeof(long long));
for(long long int i;i<n;i++)
{scanf("%lld",a);
a++;

}
qsort(a,n,sizeof(a[0]),cmp);
max=a[1]-a[0];
for(int j=1;j<n-1;j++)
{temp=a[j+1]-a[j];
    if(temp>a) a=temp;
}
printf("%lld",a[n-1]-a[0]-max);}
