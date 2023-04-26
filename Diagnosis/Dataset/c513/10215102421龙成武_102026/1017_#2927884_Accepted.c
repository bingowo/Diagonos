#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    long long int Res;
    long long int Temp1;
    long long int Temp2;
}dd;
int changedigit(char *p);
void sumupdigit(dd* pd);
int main()
{
    char c[51],*p,*q;
    long long int mul=1;
    dd* pd,*pd2;

    scanf("%s",c);
    q=c-1;
    p=c+strlen(c)-1;

    pd=(dd*)malloc(sizeof(dd));
    pd->Res=pd->Temp1=pd->Temp2=0;

    pd2=(dd*)malloc(sizeof(dd));
    pd2->Res=pd2->Temp1=pd2->Temp2=0;

    while(p!=q)
    {
        if(*p!='('&& *p!=')'&&mul==1)
        {
            pd->Temp1=changedigit(p);
            sumupdigit(pd);
        }
        else if(*p==')')
        {
            mul*=1000;
        }
        else if(*p!='(')
        {
            pd2->Temp1=changedigit(p);
            sumupdigit(pd2);

        }
        else if(*p=='(')
        {
            pd2->Res*=mul;
            mul=1;
            pd->Temp1=pd2->Res;
            sumupdigit(pd);
            while(*p=='(')
                    p--;
            p++;
        }
        p--;
    }
    printf("%lld",pd->Res);
    return 0;
}
int changedigit(char *p)
{
    int temp1;
    switch(*p)
    {
    case 'I':
        temp1=1;break;
    case 'V':
        temp1=5;break;
    case 'X':
        temp1=10;break;
    case 'L':
        temp1=50;break;
    case 'C':
        temp1=100;break;
    case 'D':
        temp1=500;break;
    case 'M':
        temp1=1000;break;
    }
    return temp1;
}
void sumupdigit(dd* pd)
{
    if(pd->Temp1!=pd->Temp2)
    {
        if(pd->Res<pd->Temp1)
        {
            pd->Res+=pd->Temp1;
        }
        else
        {
            pd->Res-=pd->Temp1;
        }

    }
    else
    {
        pd->Res+=pd->Temp1;
    }
    pd->Temp2=pd->Temp1;
}
