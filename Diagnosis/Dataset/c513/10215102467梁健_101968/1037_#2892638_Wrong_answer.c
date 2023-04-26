#include<stdio.h>
#include<string.h>
#include<math.h>
int comp1(const void *a,const void *b)
{
    unsigned long long a1=*(unsigned long long *)a,b1=*(unsigned long long *)b;
    return (a1>b1)?1:-1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    unsigned long long s[n];
    for(int i=0;i<n;i++)scanf("%llu",&s[i]);
    qsort(s,n,sizeof(unsigned long long),comp1);
    unsigned long long R=0;
    unsigned long long minus1[n-1];
    for(int i=0;i<n-1;i++)minus1[i]=s[i+1]-s[i];
    unsigned long long minus[n-m];
    for(int sp=0;sp<n-m;sp++){
        minus[sp]=0;
        for(int z=0;z<m-1;z++){
            minus[z]=minus[z]+minus1[z+sp]*(z+1);
        }
    }
    qsort(minus,n-m,sizeof(unsigned long long),comp1);
    printf("%llu",minus[0]);
    return 0;
}
