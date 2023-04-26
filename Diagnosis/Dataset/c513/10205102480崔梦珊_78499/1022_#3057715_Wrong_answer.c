#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct mail
{
    char name[1000];
    char addr[1000];
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

int main()
{
    int n;
    scanf("%d",&n);
    struct mail ans[1000];
    char c=getchar();
    for(int i=0;i<n;i++)
    {
        int wei=0;
        while((c=getchar())!='@')
        {
            ans[i].name[wei]=c;
            wei++;
        }
        int wei1=0;
        while((c=getchar())!='\n')
        {
            ans[i].addr[wei1]=c;
            wei1++;
        }
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s@%s\n",ans[i].name,ans[i].addr);
    }
    return 0;
}
