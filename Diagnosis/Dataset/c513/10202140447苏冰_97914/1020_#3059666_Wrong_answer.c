#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct SSS
{
    char day[15];
    char hour[10];
    int size;
    unsigned char name[70];
} sss;

int cmp1(const void*_a,const void*_b)
{
    sss*a=(sss*)_a;
    sss*b=(sss*)_b;
    return strcmp(a->name,b->name);
}

int cmp2(const void*_a,const void*_b)
{
    sss*a=(sss*)_a;
    sss*b=(sss*)_b;
    if(a->size != b->size) return a->size - b->size;
    else return strcmp(a->name,b->name);
}

int cmp3(const void*_a,const void*_b)
{
    sss*a=(sss*)_a;
    sss*b=(sss*)_b;
    if(strcmp(a->day,b->day)!=0) return strcmp(a->day,b->day);
    else if(strcmp(a->hour,b->hour)!=0)  return strcmp(a->hour,b->hour);
    else return strcmp(a->name,b->name);
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        sss s[110];
        for(int i=0; i<n; i++)
        {
            scanf("%s%s%d%s",s[i].day,s[i].hour,&s[i].size,s[i].name);
        }
        char x[20];
        gets(x);
        gets(x);
        if(strcmp(x,"LIST /NAME")==0)
        {
            qsort(s,n,sizeof(sss),cmp1);
        }
        else if(strcmp(x,"LIST /SIZE")==0)
        {
            qsort(s,n,sizeof(sss),cmp2);
        }
        else if(strcmp(x,"LIST /TIME")==0)
        {
            qsort(s,n,sizeof(sss),cmp3);
        }
        for(int i=0;i<n;i++)
        {
            printf("%s %s %16d %s\n",s[i].day,s[i].hour,s[i].size,s[i].name);
        }
        printf("\n");
    }
    return 0;
}

