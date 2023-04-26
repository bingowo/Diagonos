#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char s[16];
    long long n;
}str;
int cmp(const void *a,const void *b)
{
    str* a0=(str*)a;
    str* b0=(str*)b;
    if(a0->n>b0->n)
        return 1;
    else if(a0->n<b0->n)
        return -1;
    else
        return strcmp(a0->s,b0->s);
}
int main()
{
    long long t,i,j,l,n,n0;
    int a[123];
    str x[10000];
    scanf("%lld",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(x[i].s);
        x[i].n=0;
        for(j=0;j<123;j++)
            a[j]=-1;
        l=strlen(x[i].s);
        n=0;
        for(j=0;j<l;j++)
            if(a[x[i].s[j]]==-1){
                if(n==0)
                    a[x[i].s[j]]=1;
                else if(n==1)
                    a[x[i].s[j]]=0;
                else
                    a[x[i].s[j]]=n;
                n++;
            }
        n0=1;
        if(n==1)
            n=2;
        for(j=l-1;j>=0;j--){
            x[i].n=x[i].n+a[x[i].s[j]]*n0;
            n0=n0*n;
        }
    }
    qsort(x,t,sizeof(x[0]),cmp);
    for(i=0;i<t;i++)
        printf("%s\n",x[i].s);
    return 0;
}
