#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    long long int Res;
    int Temp1;
    int Temp2;
}dd;
int changedigit(char *p);
void sumupdigit(dd* pd);
int main()
{
    char c[51],stack[51],*p,*q;         //2都是在有括号的情况下，即第二情况
    dd* pd;
    int i=0;

    scanf("%s",c);
    q=c-1;
    p=c+strlen(c)-1;

    pd=(dd*)malloc(sizeof(dd));
    pd->Res=pd->Temp1=pd->Temp2=0;


    while(p!=q)
    {
        if(*p!='('&& *p!=')'&&stack[0]!=')')
        {
            pd->Temp1=changedigit(p);
            sumupdigit(pd);
        }
        else
        {

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
