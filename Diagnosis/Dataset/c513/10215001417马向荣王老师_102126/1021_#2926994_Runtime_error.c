#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int p[26];
int cmp(const void *a,const void *b)
{
    char *s1,*s2;
    char c1,c2;
    *s1=(char*)a;
    *s2=(char*)b;
    while(*s1 && *s2)
    {
        c1=(*s1)>='a'?s1-'32':s1;
        c2=(*s2)>='a'?s2-'32':s2;
        if(p[c1-'A']!=p[c2-'A']) return p[c1-'A']-p[c2-'A'];
        else
        {
            s1++;
            s2++;
        }
    }
    if(*s1==0) return -1;
    else return 1;
}
int main(void)
{   
    char s[27];
    int line=0,row,i=0;
    while((scanf("%s\n",s))!=EOF)
    {
        for(int i=0;i<26;i++)
        {
            p[s[i]-'A']=i;
        }
        char a[100][21];
        char str[2200];
        gets(str);
        while(1)
        {
            row=0;
            while(str[i]!=' ' && str[i]!=0)
            {
                a[line][row++]=str[i++];
            }
            a[line][row]='\0';
            line++;
            if(!str[i]) break;
            else i++;
        }
        qsort(a,line,sizeof(a[0]),cmp);
        int j=0;
        for(j=0;j<line-1;j++) printf("%s",a[j]);
        printf("%s\n",a[j]);
    }
    return 0;
}
