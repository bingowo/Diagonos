#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef long long lli;
typedef struct CNode* Complex;

struct CNode{
    lli rel;
    lli img;
};

lli llabs(lli x)
{
    return x>0?x:-x;
}

Complex Create(lli rel,lli img)
{
    Complex temp = (Complex)malloc(sizeof(struct CNode));
    temp->rel=rel;
    temp->img=img;
    return temp;
}

Complex Read(char s[])
{
    Complex ret = Create(0, 0);
    char *pi = strchr(s, 'i'),*pp = strchr(s, '+'),*pm = strchr(s+1, '-');
    char *p=s;
    int isplus=1,ispure=(!pp&&!pm&&pi);
    if (ispure) {
        if (*p=='i') {
            ret->img=1;
        }
        else if(*(pi-1)=='-'){
            ret->img=-1;
        }
        else{
            if (*p=='-') {
                isplus=-1;
                p++;
            }
            while (*p!='i') {
                ret->img=ret->img*10+(*p-'0');
                p++;
            }
            ret->img*=isplus;
        }
    }
    else{
        if(*p=='-'){
            isplus=-1;
            p++;
        }
        while (*p&&(*p!='+')&&(*p!='-')) {
            ret->rel=ret->rel*10+(*p-'0');
            p++;
        }
        ret->rel*=isplus;
        isplus=1;
        if(pi){
            if(pp==pi-1){
                ret->img=1;
            }
            else if(pm==pi-1){
                ret->img=-1;
            }
            else{
                if(pm){
                    isplus=-1;
                }
                p++;
                while (*p!='i') {
                    ret->img=ret->img*10+(*p-'0');
                    p++;
                }
                ret->img*=isplus;
            }
        }
    }
    return ret;
}
void ComplexToBin(Complex c,char bi[])
{
    lli a=c->rel,b=c->img;
    lli a0=1,b0=1,qa=0,qb=0;
    int mod=-2,digit=0;
    int index=148;
    while (a!=0||b!=0) {
        if(llabs(a)%2==llabs(b)%2){
            digit=0;
        }
        else{
            digit=1;
        }
        bi[index--]=digit+'0';
        a-=digit;
        qa=a*a0-b*b0;
        qb=a*a0+b*b0;
        a=qa/mod;
        b=qb/mod;
    }
    memmove(bi, bi+index+1, 149-index);
}

int main(void)
{
    char s[50],bi[150]={'0'};
    scanf("%s",s);
    Complex c=Read(s);
    if(c->rel==0&&c->img==0){
        printf("0");
    }
    else{
        ComplexToBin(c, bi);
        printf("%s",bi);
    }
    free(c);
    return 0;
}
