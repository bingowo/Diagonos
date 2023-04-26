#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int p[26]={0};

int cmp(const void*a,const void*b)
{
    char*s1;
    char*s2;
    char c1,c2;
    s1=(char*)a;
    s2=(char*)b;
    while(*s1&&*s2)
    {
        if(*s1>='a') c1=*s1-32;
        else c1=*s1;
        if(*s2>='a') c2=*s2-32;
        else c2=*s2;
        if(p[c1-'A']!=p[c2-'A'])
            return p[c1-'A']-p[c2-'A'];
        else
        {
            s1++;
            s2++;
        }
    }
    if(*s1==0) return -1;
    else return 1;
}

int main()
{
    int cnt,k,t;
    char al[27];
    while(scanf("%s\n",al)!=EOF)
    {
        for(int i=0;i<26;i++)
        {
            p[al[i]-'A']=i;
        }
        char s[101][21];
        char c[2122];
        gets(c);
        cnt=0;
        t=0;
        while(1)
        {
            k=0;
            while(c[t]&&c[t]!=' ')
            {
                s[cnt][k++]=c[t++];
            }
            s[cnt][k]='\0';
            cnt++;
            if(!c[t]) break;
            else t++;
        }
        qsort(s,cnt,sizeof(s[0]),cmp);
        for(k=0;k<cnt-1;k++)
        {
            printf("%s ",s[k]);
        }
        printf("%s\n",s[k]);
    }
    return 0;
}
