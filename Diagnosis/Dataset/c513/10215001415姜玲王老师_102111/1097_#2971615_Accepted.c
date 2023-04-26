#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char a[81]={0},c[81];
    int i=0,j;
    for(;i<80;i++)
    {
        a[i]=' ';
    }
    while(scanf("%s",c)!=EOF)
    {
        char b[161][81];
        for(i=0;i<161;i++)
        {
            for(j=0;j<80;j++)
                b[i][j]=' ';
            b[i][j]=0;
        }
        b[80][0]=c[0];
        j=80;
        for(i=1;i<strlen(c);i++)
        {
            if(c[i]>c[i-1]){b[--j][i]=c[i];}
            if(c[i]==c[i-1]){b[j][i]=c[i];}
            if(c[i]<c[i-1]){b[++j][i]=c[i];}
        }
        for(i=0;i<160;i++)
        {
            if(strcmp(a,b[i])) printf("%s\n",b[i]);
        }
    }
}
