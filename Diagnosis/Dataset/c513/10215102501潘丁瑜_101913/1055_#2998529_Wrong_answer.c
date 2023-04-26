#include <stdio.h>
#include <stdlib.h>

int main()
{
    //a做为对照的组
    char a[1000]={0};
    char ch;
    do{
        ch=getchar();
        if(a[ch] == 0 )
            printf("%c",ch);
        a[ch]= '1';
    }while(ch!='\n');
    return 0;
}
