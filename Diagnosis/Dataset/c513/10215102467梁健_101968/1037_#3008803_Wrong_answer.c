#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int cmp(const void *a,const void *b)
{
    int x=*(int *)a,y=*(int *)b;
    return x>y?1:-1;
}
int main()
{
    int n,m;scanf("%d %d",&n,&m);
    long s[n];
    for(int i=0;i<n;i++)scanf("%d",&s[i]);
    qsort(s,n,sizeof(long),cmp);
    long res=0;
    for(int i=0;i<m;i++){
        res+=(s[m-1]-s[i]);
    }
    for(int i=m;i<n;i++){
        long jud=0;
        for(int j=i-m;j<i;j++){
            jud+=(s[i-1]-s[j]);
        }
        if(jud<res)res=jud;
    }
    printf("%ld",res);
    return 0;
}
