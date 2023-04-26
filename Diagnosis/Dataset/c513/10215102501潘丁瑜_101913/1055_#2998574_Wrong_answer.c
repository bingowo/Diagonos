#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //a做为对照的组
    char a[1000]={0};
    char s[100000]={0};
    char max[100000]={0};
    int i=0,j=0;
    char ch;
    do{
        ch=getchar();
        if(a[ch] == 0 )
            s[i++]=ch;
        else
        {
            if(strlen(s) > strlen(max))
                strcpy(max,s);
            j=0;
            while(s[j] != 0) s[j++] = 0;
            for(j=0;j<1000;j++)
                a[j]=0;
            i=0;
            s[i++]=ch;
        }
        a[ch] = '1';
    }while(ch!='\n');

    if(max[0] == 0) strcpy(max,s);
    printf("%s",max);
    return 0;
}