#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct{char c[11];} string;
double change (string* s)
{
    if (strcmp(s->c,"+")==0)
    {
        string *q=s+1;
        if (strcmp(q->c,"+")!=0&&strcmp(q->c,"-")!=0&&strcmp(q->c,"*")!=0&&strcmp(q->c,"/")!=0)
            return change(s+1)+change(s+2);
        else return change(s+1)+change(s+4);
    }
    if (strcmp(s->c,"-")==0)
    {
        string *q=s+1;
        if (strcmp(q->c,"+")!=0&&strcmp(q->c,"-")!=0&&strcmp(q->c,"*")!=0&&strcmp(q->c,"/")!=0)
            return change(s+1)-change(s+2);
        else return change(s+1)-change(s+4);
    }
    if (strcmp(s->c,"*")==0)
    {
        string *q=s+1;
        if (strcmp(q->c,"+")!=0&&strcmp(q->c,"-")!=0&&strcmp(q->c,"*")!=0&&strcmp(q->c,"/")!=0)
            return change(s+1)*change(s+2);
        else return change(s+1)*change(s+4);
    }
    if (strcmp(s->c,"/")==0)
    {
        string *q=s+1;
        if (strcmp(q->c,"+")!=0&&strcmp(q->c,"-")!=0&&strcmp(q->c,"*")!=0&&strcmp(q->c,"/")!=0)
            return change(s+1)/change(s+2);
        else return change(s+1)/change(s+4);
    }
    else return atof(s->c);
}
int main ()
{
    int T;
    scanf ("%d",&T);
    getchar();
    for (int q=0;q<T;q++)
    {
        char cc;
        string s[101]={};
        int len=0,num=0,i=0;
        while ((cc=getchar())!='\n')
        {
            if (cc!=' ')
                s[len].c[num++]=cc;
            else
            {
                len++;
                num=0;
            }
        }
        printf("case #%d:\n%.6f\n",q,change(s));
    }
    return 0;
}
