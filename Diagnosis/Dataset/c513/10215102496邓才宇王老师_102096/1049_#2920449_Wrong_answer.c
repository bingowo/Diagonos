#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *p1,const void *p2)
{
    char *a=p1;
    char *b=p2;
    while(*a&&*b)
    {
        if(*a!=*b) return *a-*b;
        else
        {
            a++;
            b++;
        }
    }
    if(*a==0) return -1;
    else return 1;
}
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int k=0;k<T;k++)
    {
        char s[501];
        gets(s);
        char s1[501][501];
        int x=0,y=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='a'&&s[i]<='z') s1[x][y++]=s[i];
            else
            {
                s1[x][y]='\0';
                x++;
                y=0;
            }
        }
        if(s[strlen(s)-1]>='a'&&s[strlen(s)-1]<='z') x++;
        qsort(s1,x,sizeof(s1[0]),cmp);
        char s2[501][501];
        int w=0;
        int r=0;
        for(int q=0;q<x;q++)
        {
            int e=0;
            for(;e<w;e++)
            {
                if(strcmp(s1[q],s2[e])==0) break;
            }
            if(e==w)
            {
                strcpy(s2[r++],s1[q]);
                w++;
            }
        }
        printf("case #%d:\n",k);
        for(int j=0;j<r;j++)
        {
            if(s2[j]!=' ')
            printf("%s ",s2[j]);
        }
        printf("\n");
    }
}
