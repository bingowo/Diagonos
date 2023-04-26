#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base64_chart[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char s[101];
char ascii[808];
char ascii1[1080];
char result[200];

void tento2(char *s)
{
    int i,n,t,j;//n是原数，t是余数
    for(i=0;i<strlen(s);i++)
    {
        n=s[i];
        for(j=0;n!=0;j++)
        {
            t=n%2;
            n=n/2;
            ascii[8*(i+1)-1-j]=t+48;
        }
        for(j++;j<=7;j++)
        {
            ascii[8*(i+1)-1-j]=48;
        }
    }
}

void eightto6(char *ascii)
{
    int i,j;
    while(strlen(ascii)%6!=0)
    {
        ascii[strlen(ascii)]=48;
    }
    for(i=0;i<strlen(ascii)%6;i++)
    {
        for(j=5;j>=0;j++)
        {
            ascii1[i*8+j+2]=ascii[i*6+j];
        }
        ascii1[i*8]=48;
        ascii[i*8+1]=48;
    }
}

void twoto10(char *ascii1)
{
    int i,t,j;
    for(i=0;i<strlen(ascii1);i++)
    {
        t=ascii1[i*8]*2+ascii1[i*8+1];
        for(j=2;j<8;j++)
        {
            t=t*2+ascii1[i*8+j];
        }
        result[i]=t;
    }
    if(strlen(result)<4)
    {
        while(strlen(result)<4)
            result[strlen(result)]="=";
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",s);
        tento2(*s);
        eightto6(*ascii);
        twoto10(*ascii1);
        printf("case #%d:\n",i);
        printf("%s\n",result);
    }
    return 0;
}
