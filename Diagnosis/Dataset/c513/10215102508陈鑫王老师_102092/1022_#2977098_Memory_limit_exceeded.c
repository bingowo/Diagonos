#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[1000001];
    char s1[1000001];
    char s2[1000001];
}email;
void dep(char s[],char s1[],char s2[])
{
    char *p=s,*p1=s1,*p2=s2;
    while(*p!='@')
    {
        *p1=*p;
        p++;
        p1++;
    }
    p++;
    while(*p)
    {
        *p2=*p;
        p++;
        p2++;
    }
}
int cmp(const void* a,const void*b)
{
    email* x=(email*)a;
    email* y=(email*)b;
    if(strcmp(x->s2,y->s1)!=0)return strcmp(x->s2,y->s2);
    else return strcmp(y->s1,x->s1);
}
int main()
{
    int n;
    scanf("%d",&n);
    email ans[n];
    for(int i=0;i<n;i++)
    {

        scanf("%s",ans[i].s);
        dep(ans[i].s,ans[i].s1,ans[i].s2);
    }
    qsort(ans,n,sizeof(email),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",ans[i].s);
    }
    return 0;

}
