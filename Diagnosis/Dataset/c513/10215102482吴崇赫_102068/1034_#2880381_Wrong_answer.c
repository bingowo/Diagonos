#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105

double fluent(char c,double* f)
{
    if(c>='A'&&c<='Z')return f[c-'A'];
    else return f[c-'a'];
}
double f[27]={0.00};

int cmp(const void* a,const void* b)
{
    char s=*(char*)a;char t=*(char*)b;
    if(fluent(s,f)!=fluent(t,f))return fluent(s,f)<fluent(t,f)?1:-1;
    else return s<t?1:-1;
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        for(int i=0;i<26;++i)scanf("%f",&f[i]);
        char s[N]={'\0'};
        scanf("%s",s);
        int n=strlen(s);
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",x++);
        printf("%s\n",s);
    }
    return 0;
}
