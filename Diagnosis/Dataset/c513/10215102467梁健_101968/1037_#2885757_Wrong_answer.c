#include<stdio.h>
#include<string.h>
#include<math.h>
int comp1(const void *a,const void *b)
{
    long long a1=*(long long *)a,b1=*(long long *)b;
    return (a1>b1)?1:-1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long s[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&s[i]);
    }
    qsort(s,n,sizeof(long long),comp1);
    long long res[m];
    for(int i=0;i<m;i++){
        res[i]=s[i];
    }
    unsigned long long R=0;
    for(int i=0;i<m-1;i++){
        R=R+(res[m-1]-res[i]);
    }
    printf("%llu",R);
    return 0;
}
