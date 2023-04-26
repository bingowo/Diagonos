#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
QWERTYUIOPASDFGHJKLZXCVBNM
hat cat bat book bookworm Dallas Austin Houston fire firefox fumble
QWERTYUIOPASDFGHJKLZXCVBNM
How are you
QAZWSXEDCRFVTGBYHNUJMIKOLP
How are you
ABCDEFGHIJKLMNOPQRSTUVWXYZ
How are you
*/
char order[27]={'0'};
int cmp(const void *a,const void *b);
int cha(char *a,char *b);
int tu(char a);

int main()
{
    char ord[27]={'0'};
    char x[2001]={'0'};
    while(scanf("%s\n",ord)!=EOF)
    {
        strcpy(order,ord);
        gets(x);
        int len=strlen(x);
        int i,j1=0,j2=0;
        char s[101][101]={0};
        for(i=0;i<len;i++)
        {
            if(x[i]!=' ')
            {
                s[j1][j2]=x[i];
                j2++;
            }
            else
            {
                j1++;
                j2=0;
            }
        }
        j1++;
        qsort(s,j1,sizeof(s[0]),cmp);
        for(i=0;i<j1;i++)
        {
            len=strlen(s[i]);
            for(j2=0;j2<len;j2++)
            {
                printf("%c",s[i][j2]);
            }
            if(i<j1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}

int cmp(const void *a,const void *b)
{
    char x[100],y[100];
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
