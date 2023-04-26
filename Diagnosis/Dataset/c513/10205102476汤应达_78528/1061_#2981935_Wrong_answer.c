#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c[250];
typedef struct word
{
    char w[20];
    unsigned long long r;
}word;

int cmp(const void*a,const void*b)
{
    word a0=*(word*)a,b0=*(word*)b;
    if(a0.r!=b0.r) {return a0.r>b0.r?1:-1;}
    else {return strcmp(a0.w,b0.w);}
}

unsigned long long trans(char*s)
{
    if((int)strlen(s)==1) return 1;
    memset(c,-1,sizeof(c));c[(int)s[0]]=1;
    int cnt=2,i=1;
    while (c[(int)s[i]]==1) i++;
    c[(int)s[i++]]=0;
    for(;i<(int)strlen(s);i++)
        if(c[(int)s[i]]==-1) c[(int)s[i]]=cnt++;
    unsigned long long ans=0,ex=1;
    while (i>=1)
    {
        ans+=c[(int)s[i-1]]*ex;
        ex*=cnt;
        i--;
    }
    return ans;
}

int main()
{
    int n;scanf("%d",&n);
    word W[n];
    for(int i=0;i<n;i++) {scanf("%s",W[i].w);W[i].r=trans(W[i].w);}
    qsort(W,n,sizeof(W[0]),cmp);
    for(int i=0;i<n;i++) printf("%s\n",W[i].w);

    return 0;
}