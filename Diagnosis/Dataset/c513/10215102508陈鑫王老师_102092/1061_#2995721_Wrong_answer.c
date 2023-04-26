#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ch
{
    char s[16];
    long long int a;
};
long long int num(char s[])
{
    long long int a[63];
    memset(a,-1,63*sizeof(int));
    long long int ret=0,flag=0,len=strlen(s),wei=2;
    if(len>1)
    {
    if(s[0]<='9')
    {a[s[0]-'0']=1;
    }
    else if(s[0]>='A'&&s[0]<='Z')
    {
        a[s[0]-'A'+10]=1;
    }
    else
    a[s[0]-'a'+36]=1;

    for(int i=1;i<len;i++)
    {
        if(s[i]<='9'&&a[s[i]-'0']==-1)
        {
            if(flag==1)flag++;
            a[s[i]-'0']=flag;
            if(flag>1)wei++;
            flag++;
        }
        else if(s[i]<='Z'&&s[i]>='A'&&a[s[i]-'A'+10]==-1)
        {
            if(flag==1)flag++;
            a[s[i]-'A'+10]=flag;
            if(flag>1)wei++;
            flag++;
        }
        else if(s[i]>='a'&&a[s[i]-'a'+36]==-1)
        {
            if(flag==1)flag++;
            a[s[i]-'a'+36]=flag;
            if(flag>1)wei++;
            flag++;
        }

    }
    for(int i=0;i<len;i++)
    {
        if(s[i]<='9') ret=ret*wei+a[s[i]-'0'];
        else if(s[i]<='Z'&&s[i]>='A') ret=ret*wei+a[s[i]-'A'+10];
        else ret=ret*wei+a[s[i]-'a'+36];
    }
    }
    return ret;
}
int cmp(const void*a,const void*b)
{
    struct ch* x=(struct ch*)a;
    struct ch* y=(struct ch*)b;
    if(x->a!=y->a) return x->a<y->a?-1:1;
    else return strcmp(x->s,y->s)<=0?-1:1;
}
int main()
{
    int n;
    scanf("%d",&n);
    struct ch ans[10000];
    for(int i=0;i<n;i++)
    {
        scanf("%s",ans[i].s);
        ans[i].a=num(ans[i].s);
    }
    qsort(ans,n,sizeof(struct ch),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",ans[i].s);
    }
    return 0;
}
