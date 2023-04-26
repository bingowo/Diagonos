#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct mail
{
    char *name;
    char *addr;
};

int cmp(const void* a,const void* b)
{
    struct mail* x=(struct mail*) a;
    struct mail* y=(struct mail*) b;
    int name1=strcmp(x->name,y->name);
    int addr1=strcmp(x->addr,y->addr);
    if(addr1==0)
    {
        return -name1;
    }
    return addr1;
}

char aa[10000000]={0};

int main()
{
    int n;
    scanf("%d",&n);
    struct mail ans[n];
    char c=getchar();
    int len=0;
    for(int i=0;i<n;i++)
    {
        ans[i].name=aa+len;
        while((c=getchar())!='@')
        {
            aa[len]=c;
            len++;
        }
        aa[len]='\0';
        len++;
        ans[i].addr=aa+len;
        while((c=getchar())!='\n')
        {
            aa[len]=c;
            len++;
        }
        aa[len]=0;
        len++;
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s@%s\n",ans[i].name,ans[i].addr);
    }
    return 0;
}
