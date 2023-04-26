#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ch[27];
    int ch1[26];
    while(scanf("%s\n",ch)!=EOF)
    {
        int ch1[26];
    for(int i=0;i<26;i++)
    {
        ch1[ch[i]-'A']=i;
    }
    char s[2010];
    char s1[101][21];
    gets(s);
    int m=0,n=0;
    for(int j=0;j<strlen(s);j++)
    {
        if(s[j]!=' ')
        {
            s1[m][n]=s[j];
            n++;
        }
        else
        {
            s1[m][n]="\0";
            m++;
            n=0;
        }
    }
    s1[m][n]="\0";
    int cmp(const  void* p1,const void* p2)
{
    char* a=(char *)p1;
    char* b=(char *)p2;
    char c1,c2;
    while(*a&&*b)
    {
        c1=*a>='a'? *a-32:*a;
        c2=*b>='a'? *b-32:*b;
    if( ch1[c1-'A']!=ch1[c2-'A']) return  ch1[c1-'A']-ch1[c2-'A'];
    else
    {
        a++;b++;
    }
    }
    if(*a==0) return -1;
    else return 1;
}
    qsort(s1,m,sizeof(s1[0]),cmp);
    int k;
    for(k=0;k<m;k++)
        printf("%s ",s1[k]);
        printf("%s\n",s1[k]);
    }

}
