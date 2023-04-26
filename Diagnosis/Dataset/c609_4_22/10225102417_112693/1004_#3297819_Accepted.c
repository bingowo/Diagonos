#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void trans(int N,int R)
{
    if(N>0)
    {   trans(N/R,R);
        putchar(table[N%R]);
    }
}


int main()
{
    int A,B;
    int a=0;
    int i=0;
    char s[100];
    scanf("%d %s %d",&A,&s,&B);
    if(s[0]=='0'){i=1;}
    for(;i<strlen(s);i++)
    {
        if(s[i]>58){s[i]=toupper(s[i])-55;}
        else{s[i]=s[i]-48;}
        a=a*A+s[i];
        //printf("%d %d\n",a,s[i]);
    }

    if(a==0)putchar(table[0]);
    else trans(a,B);

    return 0;
}
