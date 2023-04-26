#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double p[27];
for(int i=0;i<26;i++)scanf("%lf",&p[i]);

int cmp(const void*a,const void*b)
{
    char ch1,ch2;
    int p1,p2;
    ch1=*((char*)a);
    ch2=*((char*)b);
    if(ch1>='a'&&ch1<='z')p1=ch1-'a';
    else p1=ch1-'A';
    if(ch2>='a'&&ch2<='z')p2=ch2-'a';
    else p2=ch2-'A';
    if(p[p2]>p[p1]) return 1;
    else if(fabs(p[p2]-p[p1])<1e-8)
    {
        if(p1==p2)return ch2-ch1;
        else return p1-p2;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
    printf("case #%d:\n",j);
    double p[27];
    for(int i=0;i<26;i++)scanf("%lf",&p[i]);
    char str[101];
    scanf("%s",str);
    qsort(str,strlen(str),sizeof(str[0]),cmp);
    printf("%s\n",str);
    }
    return 0;
}