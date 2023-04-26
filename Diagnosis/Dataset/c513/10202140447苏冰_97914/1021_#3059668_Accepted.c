#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int p[30];
int cmp(const void*_a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    while(*a!='\0' && *b!='\0')
    {
        char ch1=*a,ch2=*b;
        if(ch1>='a' && ch1<='z') ch1-=32;
        if(ch2>='a' && ch2<='z') ch2-=32;
        if(p[ch1-'A']!=p[ch2-'A']) return p[ch1-'A']-p[ch2-'A'];
        else
        {
            a++;
            b++;
        }
    }
    if(*a=='\0') return -1;
    else if(*b=='\0') return 1;
}

int main()
{
    char s[30];
    while(scanf("%s",s)!=EOF)
    {
        for(int i=0; i<strlen(s); i++)
        {
            p[s[i]-'A']=i;
        }
        char x[101][25];
        char c;
        int i=0;
        while(1)
        {
            scanf("%s%c",x[i++],&c);
            if(c=='\n') break;
        }
        qsort(x,i,sizeof(x[0]),cmp);
        for(int j=0; j<i-1; j++)
        {
            printf("%s ",x[j]);
        }
        printf("%s\n",x[i-1]);
    }
    return 0;
}

