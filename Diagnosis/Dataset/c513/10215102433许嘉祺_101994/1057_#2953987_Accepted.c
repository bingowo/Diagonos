#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    char c;
    char s[1002];
    s[0]=0;
    char s1[1002];
    int i=0;
    int len=0;
    while ((c=getchar())!=EOF){

        if (c>='a'&&c<='z') c=c-'a'+'A';
        if (c>=s[0])

        sprintf(s1,"%c%s",c,s);
        else
            sprintf(s1,"%s%c",s,c);
        strcpy(s,s1);
        
    }
    printf("%s\n",s);

    return 0;
}