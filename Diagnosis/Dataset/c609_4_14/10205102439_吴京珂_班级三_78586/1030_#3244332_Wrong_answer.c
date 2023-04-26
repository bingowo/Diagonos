#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double p[27];

int cmp(const void *a,const void *b)
{
    char ch1,ch2;
    int p1,p2;
    ch1=*((char *)a);
    ch2=*((char *)b);

    if(ch1>='a'&&ch1<='z') p1=ch1-'a';
    else p1=ch1-'A';
    if(ch2>='a'&&ch2<='z') p2=ch2-'a';
    else p2=ch2-'A';

    if(p[p2]!=p[p1]) return p[p2]-p[p1];
    else if(p[p2]==p[p1])
    {
        if(p1==p2) return ch2-ch1;
        else return p1-p2;
    }
}


int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0; i<t; i++)
    {

        for(int j=0; j<26; j++) scanf("%lf",&p[j]);//双精度
        char s[105];
        scanf("%s",s);
        int len=strlen(s);

        qsort(s,len,sizeof(s[0]),cmp);

        printf("case #%d:\n",i);
        printf("%s\n",s);

    }

    return 0;
}
