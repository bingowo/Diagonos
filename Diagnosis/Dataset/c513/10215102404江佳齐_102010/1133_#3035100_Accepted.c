#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    char t[33000]="0",*pt;
    char s[33000],*ps;
    pt=&t[0];
    ps=&s[0];
    for(int i=0;i<n;i++)
    {
        while(*pt!='\0')
        {
            if(*pt=='1') *ps='0';
            else *ps='1';
            pt++;ps++;
        }
        strcat(t,s);
        pt=&t[0];
        ps=&s[0];
    }
    printf("%s",t);
    return 0;
}
