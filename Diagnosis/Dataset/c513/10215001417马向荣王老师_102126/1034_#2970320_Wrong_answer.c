#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double p[27];
int cmp(const void *a,const void *b)
{
    char ch1,ch2;
     int p1,p2;
    ch1=*((char *)a);
    ch2=*((char *)b);
    if(ch1>='a'&&ch1<='z') p1=ch1-'a'; else p1=ch1-'A';
    if(ch2>='a'&&ch2<='z') p2=ch2-'a';  else p2=ch2-'A';
    if(p[p2]>p[p1])   return 1;
    else if(fabs(p[p2]-p[p1])<1e-8)
    {
        if(p1==p2) return ch2-ch1;
        else  return p1-p2;
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
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
    return 0;
}