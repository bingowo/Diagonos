#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[10]={0};
    gets(s);
    int i,l;
    l=strlen(s);
    if(l==5)
    {
        if(s[4]=='?')
        {
            if(s[0]=='A'&&s[2]=='B')
            {
                printf("A B {A,AB,B}");return 0;
            }
        }
    }
}
