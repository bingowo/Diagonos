#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 121

void input(char* s);
void caculate(char* s);
void output(char* s);

int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++)
    {
        char s[N];
        input(s);
        caculate(s);
        output(s);
    }
    system("pause");
    return 0;
}

void input(char* s)
{
    short c;
    int i=0;
    while((c=getchar())!='\n')
    {
        s[i++]=c;
    }  
}

void caculate(char* s)
{
    int len=strlen(s);
    int num_1=0;
    short c;
    for(int i=0;i<len;i++)
    {
        c=s[i];
        while(c!=0)
        {
            num_1+=(c&1);
            c>>=1;
        }
    }
    s[0]=num_1;
}

void output(char* s)
{
    int dividend=s[0];
    int divisor=strlen(s)*8;
    int a=dividend,b=divisor;
    int t;
    while(b>0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    printf("%d/%d\n",dividend/a,divisor/a);
}