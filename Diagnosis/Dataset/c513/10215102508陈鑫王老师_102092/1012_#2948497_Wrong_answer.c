#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef long long int lli;
typedef struct CNODE* complex;

struct CNODE{lli rel;lli ima;};
lli llabs(lli a)
{
    return a>0?a:(-a);
}

complex creatcomplex(lli rel,lli ima)
{
    complex temp=(complex)malloc(sizeof(struct CNODE));
    temp->rel=rel;
    temp->ima=ima;
    return temp;
}

lli readcomplex(char s[])
{
    complex ret=creatcomplex(0,0);
    char *pi=strchr(s,'i'),*pp=strchr(s,'+'),*pm=strchr(s+1,'-');
    char *p=s;
    int isplus=1,ispure=(!pp&&pi&&!pm);
    if(ispure)
    {
        if(*p=='i')ret->ima=1;
        else if(*(pi-1)=='-')ret->ima=-1;
        else
        {
            if(*p=='-')
            {
                isplus=-1;
                p++;
            }
            while(*p!='i')
            {
                ret->ima=ret->ima*10+(*p-'0');
                p++;
            }
            ret->ima*=isplus;
        }
    }
    else
    {
        if(*p=='-')
        {
            isplus=-1;
            p++;
        }
        while(*p&&(*p!='+')&&(*p!='-'))
        {
            ret->rel=ret->rel*10+(*p-'0');
            p++;
        }
        ret->rel*=isplus;
        isplus=1;
        if(pi)
        {
            if(pm)isplus=-1;
            if(pi==(pm+1))ret->ima=-1;
            else if(pi==(pp+1))ret->ima=1;
            else
            {
            p++;
            while(*p!='i')
            {
            ret->ima=ret->ima*10+(*p-'0');
            p++;
            }
            ret->ima*=isplus;


            }
        }

    }
    return ret;
}

void complextobin(complex c, char bi[])
{
    lli a=c->rel,b=c->ima;
    int index=148,r;
    while(a!=0||b!=0)
    {
        if(llabs(a)%2==llabs(b)%2) r=0;
        else r=1;
        bi[index--]=r+'0';
        a=(r+b-a)/2;
        b=(r-a-b)/2;
    }
    memmove(bi,bi+index+1,149-index);
}



int main()
{
    char s[50],bi[150]={'0'};
    scanf("%s",s);
    complex c=readcomplex(s);
    if(c->rel==0&&c->ima==0)printf("0");
    else
    {

    complextobin(c,bi);
    printf("%s",bi);
    }
    free(c);
    return 0;

}
