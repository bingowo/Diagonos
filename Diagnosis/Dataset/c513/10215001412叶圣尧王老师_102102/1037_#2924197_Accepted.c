#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    return *(long long*)a<*(long long*)b;
}

int main()
{
    int n,i,j,m;long long *a=malloc(1000000*sizeof(long long int)),tmp;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%lld",&a[i]);
    qsort(a,n,sizeof(long long int),cmp);
    i=0;long long max=a[i];
    long long sum=(m-1)*max,tpsum=0,tpsum2=0;
   for(int k=i+1;k<=m-1;k++)
    sum-=a[k];
    for(int k=m;k<n;k++)
    {
        tpsum+=a[i+1];i++;
        tpsum2+=a[k];
        unsigned long long tmp=sum+(a[i]-max)*(m-1)+tpsum-tpsum2;
        if(tmp<sum){
            i=k-m+1;
            tpsum2=0;
            tpsum=0;
            max=a[i];
            sum=tmp;
        }
    }
    free(a);
    printf("%lld",sum);
}
