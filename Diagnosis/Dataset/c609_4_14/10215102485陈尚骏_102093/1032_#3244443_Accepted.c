#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char s[51];
    int i=1,j=0;
    scanf("%s",s);
    for(int k=0;k<strlen(s);++k)
    {
        if(s[k]==s[k+1]||s[k+1]=='\0')
        {
            if(j<i) j=i;
            i=1;
        }
        else i++;
    }
    printf("%d\n",j);
    return 0;
}
