#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ch[27];
    int ch1[26];
    while(scanf("%s\n",ch)!=EOF)
    {
    for(int i=0;i<26;i++)
    {
        ch1[ch[i]-'A']=i;
    }
    char s[2010];
    char s1[101][21];
    gets(s);
   int count=0;int i=0;
 while(1)
 {   int j=0;
    while(s[i]!=' '&&s[i])    s1[count][j++]=s[i++];
    s1[count][j]='\0';
    count++;
   if(!s[i]) break; else i++;
}

    int cmp(const  void* p1,const void* p2)
{
        char *a,*b;char c1,c2;
    a=(char *)p1;b=(char *)p2;
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
    qsort(s1,count,sizeof(s1[0]),cmp);
    int k;
    for(k=0;k<count-1;k++)
        printf("%s ",s1[k]);
        printf("%s\n",s1[k]);
    }

}
