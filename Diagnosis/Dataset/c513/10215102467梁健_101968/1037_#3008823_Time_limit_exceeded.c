#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int cmp(const void *a,const void *b)
{
    long long x=*(long *)a,y=*(long *)b;
    return x>y?1:-1;
}
int main()
{
    int n,m;scanf("%d %d",&n,&m);
    long s[n];
    for(int i=0;i<n;i++)scanf("%ld",&s[i]);
    qsort(s,n,sizeof(long),cmp);
    long res=m*s[m-1];
    for(int i=0;i<m;i++){
        res-=s[i];
    }
    for(int i=m;i<n;i++){
        long jud=s[i]*m,cnt=0;
        for(int j=i-m+1;j<=i;j++){
            cnt+=s[j];
        }
        jud-=cnt;
        if(jud<res)res=jud;
    }
    printf("%ld",res);
    return 0;
}
