#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
    return *(long long int*)a-*(long long int*)b;

}
int main()
{
    int t,sum,n=0;
    scanf("%d",&t);
    long long int a[100000];
    while(scanf("%d",&a[n])==1)n++;
    qsort(a,t,sizeof(long long int),cmp);
    for(int i=0;i<n;i=i+2){
        sum=sum+abs(a[i+1]-a[i]);
    }
    printf("%d",sum);
    return 0;
}