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
    long long res[n-m+1],jud,cnt;
    for(int i=m-1;i<n;i++){
        jud=s[i]*m,cnt=0;
        for(int j=i-m+1;j<=i;j++){
            cnt+=s[j];
        }
        jud-=cnt;
        res[i-m+1]=jud;
    }
    qsort(res,n-m+1,sizeof(long long),cmp);
    printf("%lld",res[0]);
    return 0;
}
