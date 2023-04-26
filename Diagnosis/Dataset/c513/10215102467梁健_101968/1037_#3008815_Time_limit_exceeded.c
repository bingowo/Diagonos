#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int cmp(const void *a,const void *b)
{
    long long x=*(long long *)a,y=*(long long *)b;
    return x>y?1:-1;
}
int main()
{
    int n,m;scanf("%d %d",&n,&m);
    long long s[n];
    for(int i=0;i<n;i++)scanf("%lld",&s[i]);
    qsort(s,n,sizeof(long long),cmp);
    long long res=m*s[m-1];
    for(int i=0;i<m;i++){
        res-=s[i];
    }
    for(int i=m;i<n;i++){
        long long jud=s[i]*m;
        for(int j=i-m+1;j<=i;j++){
            jud-=s[j];
        }
        if(jud<res)res=jud;
    }
    printf("%lld",res);
    return 0;
}
