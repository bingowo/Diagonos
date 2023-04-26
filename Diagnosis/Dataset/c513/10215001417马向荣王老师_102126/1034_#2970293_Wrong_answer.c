#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double p[27];
int cmp(const void *a,const void *b)
{
    char *s1=(char *)a;
    char *s2=(char *)b;
    int p1,p2;
    if(s1<='a' && s1<='z') p1=*s1-'a';
    else p1=*s1-'A';
    if(s2<='a' && s1<='z') p2=*s2-'a';
    else p2=*s2-'A';
    if(p[p1]<p[p2]) return 1;
    else if(abs(p[p2]-p[p1])<1e-8)
    {
        if(p1==p2) return s2-s1;
        else return p1-p2;
    }
    else return -1;
}
int main(void)
{
    int T;
    scanf("%d\n",&T);
    int i=0;
    for(i=0;i<T;i++)
    {
        double p[27];
        for(int j=0;j<26;j++)
        {
            scanf("%lf",&p[j]);
        }
        char str[101];
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("%s\n",str);
    }
    return 0;
}