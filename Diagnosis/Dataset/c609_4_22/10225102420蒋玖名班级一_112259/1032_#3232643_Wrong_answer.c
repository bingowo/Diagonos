#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c=getchar();
    char d=getchar();
    int len=1,max=1;
    while(d!='\n')
    {
        if(d!=c) len++;
        else if(len>max) max=len;
        if(d==c)
            len=1;
        c=d;d=getchar();
    }
    printf("%d",max);
    return 0;
}
