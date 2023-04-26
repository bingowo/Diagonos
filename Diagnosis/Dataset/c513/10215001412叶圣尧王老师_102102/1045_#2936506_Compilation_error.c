include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
    char chr[100];
    int len;
};

struct md
{
    char c[27];
    int num[27];
};

int confer(char*a,struct md sb)
{
    int i=0,j=0;long long num=0;struct md sa;
    sa.c[0]=a[0];sa.num[0]=1;int k=0;
    for(i=1;i<strlen(a);i++)
    {
        sa.num[i]=0;
        if(a[i]==a[i-1])sa.num[k]++;
        else
        {
            k++;
            sa.c[k]=a[i];
            sa.num[k]++;
        }
    }sa.c[k+1]='\0';
    int sum=0,flag=0;
    for(j=0;j<=k;j++)
        if(sa.c[j]==sb.c[j]){sum+=abs(sa.num[j]-sb.num[j]);}
        else flag=-1;
    if(flag==-1)return -1;
    else return sum;
}

int cmp(const void*a,const void*b)
{
    return (*(struct st*)a).len<(*(struct st*)b).len;
}

int main()
{
    int T,t,k=0;
    scanf("%d",&T);struct st s[T];
    for(t=0;t<T;t++)
    {
        scanf("%s",s[t].chr);
        s[t].len=strlen(s[t].chr);
    }
    qsort(s,T,sizeof(s[0]),cmp);
    struct md sb;
    sb.c[0]=s[T/2].chr[0];sb.num[0]=1;
    for(t=1;t<strlen(s[T/2].chr);t++)
    {
        sb.num[t]=0;
        if(s[T/2].chr[t]==s[T/2].chr[t-1])sb.num[k]++;
        else
        {
            k++;
            sb.c[k]=s[T/2].chr[t];
            sb.num[k]++;
        }
    }sb.c[k+1]='\0';
    int sum=0;
    for(t=0;t<T;t++)
    {
        k=confer(s[t].chr,sb);
        if(k==-1){printf("-1");break;}
        else sum+=k;
    }
    if(t>=T)printf("%d",sum);
}
