#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str
{
    char s[31];
};
int num(const char s[])
{
    int ret=0,temp=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
           ret=ret*10+(s[i]-'0');
           temp=1;
        }
    }
    if(temp)return ret;
    else return -1;
}

int cmp(const void*a,const void*b)
{
    struct str* x=(struct str*)a;
    struct str* y=(struct str*)b;
    int m,n;
    m=num(x->s);
    n=num(y->s);
    if(m==n) strcmp(x->s,y->s);
    else if(m==-1&&n!=-1) return -1;
    else if(m!=-1&&n==-1) return 1;
    else 
    {
        return m<n?-1:1;
    }
    
}

void strnumcmp(struct str s[],int n)
{
    qsort(s,n,sizeof(struct str),cmp);
}
int main()
{
    int i=0;
    struct str s[100];
    while((scanf("%s",s[i].s))>=1)
    {
        i++;
    }
    strnumcmp(s,i);
    for(int j=0;j<i;j++)
    {
        printf("%s%c",s[j].s,(j!=i-1)?' ':'\n');
    }

    return 0;
}
