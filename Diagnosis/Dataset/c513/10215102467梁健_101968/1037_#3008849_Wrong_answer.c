#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int cmp(const void *a,const void *b)
{
    long long x=*(long long*)a,y=*(long long*)b;
    return x>y?1:-1;
}
int main()
{
    int n,m;scanf("%d %d",&n,&m);
    long long s[n];
    for(int i=0;i<n;i++)scanf("%lld",&s[i]);
    qsort(s,n,sizeof(long long),cmp);
    long long res[n-m+1],cnt=0;
    for(int i=0;i<m;i++){
        cnt+=s[i];
        res[0]=s[m-1]*m-cnt;
    }
    for(int i=m;i<n;i++){
        res[i-m+1]=res[i-m]+s[i-m]-s[i]-m*s[i-1]+m*s[m];
    }
    qsort(res,n-m+1,sizeof(long long),cmp);
    printf("%lld",res[0]);
    return 0;
}
