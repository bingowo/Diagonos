#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct data
{
    char YEAR[100];
    char TIME[100];
    char EMPTY[100];
    int SIZE;
    char NAME[100];
};

int cmpn(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a),d2=*((struct data*)b);
    return strcmp(d1.NAME,d2.NAME);
}

int cmps(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a),d2=*((struct data*)b);
    int t=d1.SIZE-d2.SIZE;
    if(t==0) t=strcmp(d1.NAME,d2.NAME);
    return t;
}

int cmpt(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a),d2=*((struct data*)b);
    int t=strcmp(d1.YEAR,d2.YEAR);
    if(t==0)
    {
        t=strcmp(d1.TIME,d2.TIME);
        if(t==0) t=strcmp(d1.NAME,d2.NAME);
    }
    return t;
}

int main()
{
    for(;;)
    {
        int n,i;
        scanf("%d",&n);
        if(n==0) break;
        struct data FILE[100];
        for(i=0;i<n;i++)
        {
            int j;
            scanf("%s",FILE[i].YEAR);scanf("%s",FILE[i].TIME);
            for(j=0;(FILE[i].EMPTY[j]=getchar())==' ';j++);
            FILE[i].EMPTY[j]='\0';
            scanf("%d",&FILE[i].SIZE);scanf("%s",FILE[i].NAME);
        }
        char mid[100],need[100];scanf("%s",mid);scanf("%s",need);
        if(need[1]=='N')
        {
            qsort(FILE,n,sizeof(FILE[0]),cmpn);
            for(i=0;i<n;i++)
            {
                printf("%s %s",FILE[i].YEAR,FILE[i].TIME);
                printf("%s%d %s",FILE[i].EMPTY,FILE[i].SIZE,FILE[i].NAME);
            }

        }
        else if(need[1]=='S')
        {
            qsort(FILE,n,sizeof(FILE[0]),cmps);
            for(i=0;i<n;i++)
            {
                printf("%s %s",FILE[i].YEAR,FILE[i].TIME);
                printf("%s%d %s",FILE[i].EMPTY,FILE[i].SIZE,FILE[i].NAME);
            }
        }
        else
        {
            qsort(FILE,n,sizeof(FILE[0]),cmpt);
            for(i=0;i<n;i++)
            {
                printf("%s %s",FILE[i].YEAR,FILE[i].TIME);
                printf("%s%d %s",FILE[i].EMPTY,FILE[i].SIZE,FILE[i].NAME);
            }
        }
        return 0;
    }
}
