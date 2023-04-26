#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num;
    char c;
}group;

int main()
{
    int t,i;
    char tt[10];
    gets(tt);
    t=atoi(tt);
    for(i=0;i<t;i++)
    {
        char s[1000];
        group zu[500];
        int j,k,mid,st=0;
        memset(s,0,sizeof(char)*1000);
        memset(zu,0,sizeof(group)*500);
        gets(s);
        int len=strlen(s);

        for(j=0,k=0;j<len;j++)
        {
            if(s[j]!=s[j+1])
            {
                zu[k].c=s[j];
                mid=j-st+1;
                while(mid>255)
                {
                    zu[k].num=255;
                    mid-=255;
                    k++;
                    zu[k].c=s[j];
                }
                zu[k].num=mid;
                k++;
                st=j+1;
            }
        }
        int nofzu=k;
        printf("case #%d:\n",i);
        for(j=0;j<nofzu;j++)
        {
            printf("%d%c",zu[j].num,zu[j].c);
        }
        printf("\n");



    }
}
