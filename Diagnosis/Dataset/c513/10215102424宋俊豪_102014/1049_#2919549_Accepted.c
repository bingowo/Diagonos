#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char t[505],s[501][501],t1[501]={'\0'};
int read(char t[],char(*s)[501])
{
    int id=0,id1=0;
    while(*t)
    {
        if(*t==' '||*t==','||*t=='!'||*t=='?'||*t=='.')
        {
            s[id][id1++]='\0';id++;id1=0;
        }
        else
            s[id][id1++]=*t;
        *t++;
    }
    s[id][id1++]='\0';
    return id;
}
int cmp(const void *a,const void *b)
{
    char *x=(char *)a;char *y=(char *)b;
    return strcmp(x,y);
}
int main()
{
    int n,cnt;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        gets(t);
        cnt=read(t,s);
        qsort(s,cnt,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<=cnt;j++)
        {
           if(strcmp(s[j],t1)!=0)
            {
                printf("%s ",s[j]);
                strcpy(t1,s[j]);
            }
            else{continue;}
        }
            printf("\n");
    }
    return 0;
}
