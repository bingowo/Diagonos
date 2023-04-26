#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double change ()
{
    char s[11];
    scanf("%s",s);
    if (strcmp(s,"+")==0)
        return change()+change();
    if (strcmp(s,"-")==0)
        return change()-change();
    if (strcmp(s,"*")==0)
        return change()*change();
    if (strcmp(s,"/")==0)
        return change()/change();
    else return atof(s);
}
int main ()
{
    int T;
    scanf ("%d",&T);
    getchar();
    for (int q=0;q<T;q++)
    {
        printf("case #%d:\n%.6f\n",q,change());
    }
    return 0;
}
