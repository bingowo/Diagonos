#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char order[30];
int cmp(const void *a,const void *b);
int cha(char *a,char *b);
int tu(char a);

int main()
{

    char x[2001];
    while(scanf("%s\n",order)!=EOF)
    {
        gets(x);
        int len=strlen(x);
        int i,j1=0,j2=0;
        char s[101][21];
        for(i=0;i<len;i++)
        {
            while(x[i]!=' ')
            {
                s[j1][j2]=x[i];
                j2++;
                i++;
            }
            j1++;
        }
        qsort(s,j1,sizeof(s[0]),cmp);
        for(i=0;i<j1;i++)
        {
            len=strlen(s[i]);
            for(j2=0;j2<len;j2++)
            {
                printf("%c",s[i][j2]);
            }
            if(i<j1-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}

int cmp(const void *a,const void *b)
{
    char x[31],y[31];
    strcpy(x,(char *)a);
    strcpy(y,(char *)b);
    return cha(x,y);
}
int cha(char *a,char *b)
{
    int len1=strlen(a);
    int len2=strlen(b);
    int i;
    for(i=0;i<len1&&i<len2;i++)
    {
        if(tu(a[i])>tu(b[i]))
            return 1;
        else if(tu(a[i])<tu(b[i]))
            return -1;
    }
    if(i==len1)
        return -1;
    else
        return 1;
}
int tu(char a)
{
    int i;
    for(i=0;i<26;i++)
    {
        if(a==order[i]||a==(order[i]-'A'+'a'))
            break;
    }
    return i;
}
