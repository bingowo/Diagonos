#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

char* encode(char* buf, char* s)
{
    static const char *TranTable;






}


char* substr(char* t,char* s,int beg,int len)
{
    int i;
    for(i=0; i<len&&s[beg+i]; i++)
        t[i] = s[beg+i];
    t[i] = 0;

    return t;
}




void solve()
{
    char s[N+1], r[(N/3+1)*4+1]="";
    char t[4], buf[5];
    int i, slen;
    for(i=0; i<slen/3+(slen%3!=0); i++)
    {
        scanf("%s", s);
        slen = strlen(s);
        strcat(r,encode(buf,substr(t,s,i*3,3)));
    }
    printf("%s\n", r);
}

int main()
{
    int i, t;
    scanf("%d\n", &t);
    for(i=0; i<t; i++)
        printf("case #%d:\n", i),solve();

    return 0;
}
