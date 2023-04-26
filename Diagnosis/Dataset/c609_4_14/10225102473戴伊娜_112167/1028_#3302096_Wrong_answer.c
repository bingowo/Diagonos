#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    long long int*s1;
    long long int*s2;
    s1=(long long int*)a;
    s2=(long long int*)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2)
    {s1++;s2++;}
    return *s2-*s1;

}
int main()
{
    int T,N,j,q;
    long long int a[1000][50];
    scanf("%d",&T);
    for(int m=0;m<T;m++)
    {
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        {
            j=0;
            while(scanf("%lld",&a[i][j])&&a[i][j]!=-1)
                j++;
        }
    qsort(a,N,sizeof(a[0]),cmp);
    for(int i=0;i<N;i++)
    {
        for(q=0;a[i][q+1]!=-1;q++)
        printf("%lld ",a[i][q]);
        printf("%lld\n",a[i][q]);
    }

     }
     return 0;
}
