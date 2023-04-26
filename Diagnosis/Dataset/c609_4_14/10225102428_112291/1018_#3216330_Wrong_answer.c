#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;

}
int main()
{
    int t,sum;
    scanf("%d",&t);
    long long int a[100000];
    qsort(a,t,sizeof(long long int),cmp);
    for(int i=0;i<t;i++)printf("%lld",a[i]);
    int i=0;
    while(scanf("%lld",&a[i])==1){
        sum=sum+abs(a[i+1]-a[i]);
        i=i+2;
    }
    printf("%d",sum);
    return 0;
}