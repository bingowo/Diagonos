#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
const char* endd="END";
const char* ID="$GPRMC";

#define N 100

typedef struct
{
    char s[7];
} TIME;

void empty(char *s)
{
    for (int i=strlen(s)-1;i>=0;i--)
        s[i]=0;
}

int main()
{
    char s[1005]={0};
    TIME arr;
    do
    {
        gets(s);
        char subs[50]={0}; int a=0,i; long long x=(long long)s[1];
        for (i=0;i<strlen(s) && s[i]!=',';i++)
        {
            subs[a++]=s[i];
            if (i>=2)
                x=x^s[i];

        }
        if (strcmp(subs,ID)==0)
        {
            char time[7]={0};
            empty(subs);
            a=0;
            x=x^s[i];
            for (i=i+1;s[i]!=',';i++)
            {
                if (a<6)
                    time[a++]=s[i];
                x=x^s[i];
            }
            x=x^s[i];
            char state=s[++i]; x=x^s[i];
            if (state=='V')
                continue;
            if (state=='A')
            {
                for (i=i+1;s[i]!=',';i++)  x=x^s[i];//a,
                x=x^s[i]; for (i=i+1;s[i]!=',';i++)  x=x^s[i]; // latitude
                x=x^s[i]; for (i=i+1;s[i]!=',';i++)  x=x^s[i]; // NS
                a=0; x=x^s[i];
                for (i=i+1;s[i]!=',';i++)
                {
                    subs[a++]=s[i]; //longitude
                    x=x^s[i];
                }
                x=x^s[i];
                char direction=s[++i];
                a=0; char check[50]={0};
                for (i;i<strlen(s)&& s[i]!='*';i++)
                {
                    x=x^s[i];
                }
                for (i=i+1;i<strlen(s);i++)
                    check[a++]=s[i];
                long long d;
                sscanf(check,"%X",&d);
                x=x%65536;
                if (x==d)
                {
                    strcpy(arr.s,time);
                    char hh[3]={0};
                    hh[0]=time[0];
                    hh[1]=time[1];
                    int hour=atoi(hh);
                    hour+=8;
                    if (hour>=24)
                        hour-=24;
                    arr.s[0]=hour/10+'0';
                    arr.s[1]=hour%10+'0';
                }
            }
        }
    }
    while (strcmp(s,endd));
    for (int i=0;i<2;i++)
        printf("%c",arr.s[i]);
    printf(":");
    for (int i=2;i<4;i++)
        printf("%c",arr.s[i]);
    printf(":");
    for (int i=4;i<6;i++)
        printf("%c",arr.s[i]);
    printf("\n");
    return 0;
}