#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

void str_lower(char*p)
{
    while(*p)
    {
        *p=tolower(*p);
        p++;
    }
}

int spilt_wds(char*bf,char**dt)
{
    int n=0;
    char*p=strtok(bf," ");
    while(p)
    {
        *dt=p;
        str_lower(*dt);
        n++;
        p=strtok(NULL," ");
        dt++;
    }
    return n;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        char ln[50000];
        gets(ln);
        char**dt=(char**)malloc(1000*sizeof(char*));
        int n=spilt_wds(ln,dt);
        int cnt=n;
        for(int j=0;j<n;j++)
        {
            if(strcmp(dt[j],"the")==0||strcmp(dt[j],"a")==0||strcmp(dt[j],"an")==0||strcmp(dt[j],"of")==0||strcmp(dt[j],"for")==0||strcmp(dt[j],"and")==0)
                cnt--;
        }
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
    }
    return 0;
}
