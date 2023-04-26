#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char s[1001], t[2001];
    scanf("%s",s);
    int start=1000, end=1000;
    t[start] = toupper(s[0]);
    for(int i=1; s[i]; ++i) {
        if(toupper(s[i]) >= t[start])
            t[--start] = toupper(s[i]);
        else t[++end] = toupper(s[i]);
    }
    for(int i=start; i<=end; ++i)
        printf("%c",t[i]);
    printf("\n");
    return 0;
}
