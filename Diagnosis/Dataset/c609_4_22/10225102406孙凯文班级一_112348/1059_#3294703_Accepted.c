#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct a{
    char s[100];
    double q;
};
int cmp(const void*A,const void*B)
{
    struct a aa=*(struct a*)A;
    struct a bb=*(struct a*)B;
    if(aa.q-bb.q>0) return 1;
    else return -1;
}
int main()
{
    struct a ss[100];
    int n;
    char c;
    scanf("%d",&n);
    c=getchar();
    for(int i=0;i<n;i++)
    {
        int j=0;
        struct a a1;
        while((c=getchar())!=EOF&&c!='\n')
        {
            a1.s[j++]=c;
        }
        a1.s[j]='\0';
        a1.q=atof(a1.s);
        ss[i]=a1;
    }
    qsort(ss,n,sizeof(ss[0]),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",ss[i].s);
    }
        return 0;
}