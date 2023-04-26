#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st 
{
    char chr[100];
    int len;
};

struct md
{
    char c[101];
    int num[101];
};

int confer(char*a,char*b)
{
    int i=0,j=0;long long num=0;struct md sa,sb;
    sa.c[0]=a[0];sb.c[0]=b[0];sa.num[0]=1;sb.num[0]=1;int k=0;
    for(i=1;i<strlen(a);i++)
    {
        sa.num[i]=0;
        if(sa.c[i]==sa.c[i-1])sa.num[k]++;
        else
        {
            k++;
            sa.c[k]=a[i];
            sa.num[k]++;
        }
    }
    for(i=1;i<strlen(b);i++)
    {
        sb.num[i]=0;
        if(sb.c[i]==sb.c[i-1])sb.num[k]++;
        else
        {
            k++;
            sb.c[k]=b[i];
            sb.num[k]++;
        }
    }int sum=0,flag=-1;
    for(j=0;j<=k;j++)
        if(sa.c[j]==sb.c[j]){sum+=abs(sa.num[j]-sb.num[j]);flag=0;}
    if(flag==-1)return -1;
    else return sum;
}

int cmp(const void*a,const void*b)
{
    return (*(struct st*)a).len<(*(struct st*)b).len;
}

int main()
{
    int T,t,k;
    scanf("%d",&T);struct st s[T];
    for(t=0;t<T;t++)
    {
        scanf("%s",s[t].chr);
        s[t].len=strlen(s[t].chr);
    }
    qsort(s,T,sizeof(s[0]),cmp);
    ;int sum=0,k;
    for(t=0;t<T;t++)
    {
        k=confer(s[t].chr,s[T/2].chr);
        if(k==-1){printf("-1");break;}
        else sum+=k;
    }
    if(t>=T)printf("%d",sum);
}