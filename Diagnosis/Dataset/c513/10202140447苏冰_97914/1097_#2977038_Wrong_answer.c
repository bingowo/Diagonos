#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char s[162][81];
int main()
{
    char a[100];
    while(scanf("%s",a)!=EOF)
    {
        memset(s,' ',sizeof(s));
        int x=80,y=0;
        int cnt[162]={0};
        int min=162;int max=80;
        s[80][0]=a[0];
        for(int i=1;i<strlen(a);i++)
        {
            if(a[i]>a[i-1])
            {
                s[--x][++y]=a[i];
            }
            else if(a[i]<a[i-1])
            {
                s[++x][++y]=a[i];
            }
            else
            {
                s[x][++y]=a[i];
            }
            if(x<min) min=x;
            if(x>max) max=x;
            cnt[x]=y;
        }
        for(int i=min;i<=max;i++)
        {
            for(int j=0;j<=cnt[i];j++)
            {
                printf("%c",s[i][j]);
            }
            if(i!=max) printf("\n");
        }
        printf("\n");
    }
    return 0;
}
