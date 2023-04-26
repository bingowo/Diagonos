#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str
{
    char s[21];
};
int num(char s[])
{
    char s1[21];
    char* p=s;
    s1[0]=*p;
    s1[1]='\0';
    p++;
    while(*p!='\0')
    {
       char *p1=s1;
       if(strchr(s1,*p)==NULL)
        strncat(s1,p,1);
       p++;

    }
    return strlen(s1);
}
int cmp(const void*a,const void*b)
{
    struct str* x=(struct str*)a;
    struct str* y=(struct str*)b;
    int m=num(x->s),n=num(y->s);
    if(m!=n)return m>n?-1:1;
    else return strcmp(x->s,y->s)<=0?-1:1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        struct str ret[n];
        for(int j=0;j<n;j++)
        {
            scanf("%s",ret[j].s);
        }
        qsort(ret,n,sizeof(ret[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%s\n",ret[j].s);
        }
    }
    return 0;
}
