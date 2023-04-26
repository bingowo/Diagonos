#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define N 10000
 int num(long long int a)
{
    long long int b=1;int i=0,k=0;
    while(i<64)/*注意i不能等于64，除非i=1开始的话，就应该是i<=64*/
    {
        if(a&b){i++;k++;}
        else i++;
        a>>=1;/*a右移和b左移都可以，不需要a或者b是unsigned*/
    }
    return k;}


int compare(const void*a,const void*b)
{
    long long int m=*(long long int*)a;
    long long int n=*(long long int*)b;
    int c=num(m);
    int d=num(n);
    if(c>d)return -1;
    else if(c<d)return 1;
    else if(m>n)return 1;
    else if(m<=n)return -1;
}
void sortcomp(long long int *p,int n)
{
    qsort(p,n,sizeof(p[0]),compare);
}
int main()
{
    int i,j,n,cas,t;
    long long int s[N];
    scanf("%d",&n);
    for(t=0;t<n;t++)/*可以直接一个循环搞定，不需要先输入所有要处理的数据再操作，最后输出*/
    {
        scanf("%d",&cas);
        for(i=0;i<cas;i++)scanf("%lld",&s[i]);
        sortcomp(s,cas);
        printf("case #%d:\n",t);
        for (i=0; i<cas; i++) printf("%lld%c",s[i],i==cas-1?'\n':' ');
    }
return 0;
}
