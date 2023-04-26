#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double p[27];

int cmp(const void*a,const void*b)
{
    char ch1=*((char*)a),ch2=*((char*)b);
    int p1,p2;
    if(ch1>='a' && ch1<='z') p1=ch1-'a';
    else p1=ch1-'A';
    if(ch2>='a' && ch2<='z') p2=ch2-'a';
    else p2=ch2-'A';
    if(p[p2]>p[p1]) return 1;
    else if(fabs(p[p2]-p[p1])<1e-8)
    {
        if(p1==p2) return ch2-ch1;
        else return p1-p2;
    }
    else return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    char str[101];
    for(int i=0;i<T;i++)
    {
        for(int t=0;t<26;t++) scanf("%lf",&p[t]);
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(char),cmp);
        printf("case #%d:\n",i);
        for(int t=0;t<strlen(str);t++) printf("%c",str[t]);
        printf("\n");
    }
}
