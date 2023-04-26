#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    char c;
    char s[1000];
    s[0]=0;
    while ((c=getchar())!=EOF){
        if (c>='a'&&c<='z') c=c-'a'+'A';
        if (c>=s[0]) sprintf(s,"%c%s",c,s);
        else sprintf(s,"%s%c",s,c);
    }
    printf("%s\n",s);

    return 0;
}