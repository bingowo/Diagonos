#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//16 17
/*
5
2011-01-26 19:48           307200 ScoreStat++.exe
2011-01-26 07:32              388 ScoreStat.c
2011-01-26 19:48              429 ScoreStat.cpp
2011-01-25 20:08           270336 ScoreStat.exe
2011-01-25 20:11            22016 成绩统计 .doc
LIST /SIZE
*/
int cmp1(const void *a,const void *b);
int cmp2(const void *a,const void *b);
int cmp3(const void *a,const void *b);

int main()
{
    int n=1,i;
    while(n!=0)
    {
    scanf("%d\n",&n);
    char field[n][100];
    for(i=0;i<n;i++)
    {
        int len=strlen(field[i]);
        int j=0;
        for(j=0;j<len;j++)
        {
            field[i][j]='0';
        }
    }
    for(i=0;i<n;i++)
    {
        gets(field[i]);
    }
    char lis[100];
    gets(lis);
    char *ln={"LIST /NAME"};
    char *ls={"LIST /SIZE"};
    char *lt={"LIST /TIME"};
    if(strcmp(lis,ln)==0)
    {
        qsort(field,n,sizeof(field[0]),cmp1);
    }
    else if(strcmp(lis,ls)==0)
    {
        qsort(field,n,sizeof(field[0]),cmp2);
    }
    else if(strcmp(lis,lt)==0)
    {
        qsort(field,n,sizeof(field[0]),cmp3);
    }
    for(i=0;i<n;i++)
    {
        int len=strlen(field[i]);
        int j=0;
        for(j=0;j<len;j++)
        {
            printf("%c",field[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    }
    return 0;
}

int cmp1(const void *a,const void *b)
{
    int i;
    char aa[10000],bb[1000];
    strcpy(aa,(char *)a);
    strcpy(bb,(char *)b);
    char x[1000]={'0'},y[1000]={'0'};
    for(i=34;i<strlen(aa)||i<strlen(bb);i++)
    {
        x[i-34]=aa[i];
        y[i-34]=bb[i];
    }
    return strcmp(x,y);
}
int cmp2(const void *a,const void *b)
{
    int i,j;
    char aa[10000],bb[1000];
    strcpy(aa,(char *)a);
    strcpy(bb,(char *)b);
    char x[1000]={'0'},y[1000]={'0'};
    j=0;
    for(i=16;i<34;i++,j++)
    {
        if(isspace(aa[i])==0)
        {
            x[j]=aa[i];
        }
        else
            x[j]='0';
    }
    j=0;
    for(i=16;i<34;i++,j++)
    {
        if(isspace(bb[i])==0)
        {
            y[j]=bb[i];
        }
        else
            y[j]='0';
    }
    if(strcmp(x,y)!=0)
        return strcmp(x,y);
    else
        return cmp1(a,b);
}
int cmp3(const void *a,const void *b)
{
    int i;
    char aa[10000]={'0'},bb[1000]={'0'};
    strcpy(aa,(char *)a);
    strcpy(bb,(char *)b);
    char x[1000],y[1000];
    for(i=0;i<16;i++)
    {
        x[i]=aa[i];
    }
    for(i=0;i<16;i++)
    {
        y[i]=bb[i];
    }
    if(strcmp(x,y)!=0)
        return strcmp(x,y);
    else
        return cmp1(a,b);
}
