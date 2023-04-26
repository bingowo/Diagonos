#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int order[26];
int mycmp(void *a,void *b)
{
    char *a1=(char *)a;
    char *b1=(char *)b;
    while((toupper(*b1)==toupper(*a1))&&(*a1&&*b1))
    {
        a1++;
        b1++;
    }
    char tmpa=toupper(*a1),tmpb=toupper(*b1);
    if(*a1==0) return -1;
    if(*b1==0) return 1;
    return order[tmpa-'A']-order[tmpb-'A'];
}
int main()
{
    char input[30];
    while(scanf("%s\n",input)!=EOF)
    {
        for(int i=0;i<26;i++) order[input[i]-'A']=i;
        char str[200][40];
        int i=0,j=0;
        char c;
        while((c=getchar())!='\n')
        {
            if(c!=' ') str[i][j++]=c;
            else
            {
                str[i][j]='\0';
                i++;
                j=0;
            }
        }
        str[i][j]='\0';
        qsort(str,i+1,sizeof(str[0]),mycmp);
        for(int x=0;x<i;x++) printf("%s ",str[x]);
        printf("%s\n",str[i]);
    }
}