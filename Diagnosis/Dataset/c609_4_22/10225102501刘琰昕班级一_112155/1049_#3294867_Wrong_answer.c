#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

typedef struct
{
    int digits[MAX_LEN];
    int len;
} BigInt;

/* 初始化大数 */
void init(BigInt *a)
{
    memset(a->digits,0,sizeof(a->digits));
    a->len=0;
}

/* 大数赋值 */
void assign(BigInt *a,const char *s)
{
    init(a);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        a->digits[i]=s[len-i-1]-'0';
    }
    a->len=len;
}

/* 输出大数 */
void print(BigInt *a)
{
    for(int i=a->len-1;i>=0;i--)
    {
        printf("%d",a->digits[i]);
    }
    printf("\n");
}

/* 大数减法 */
int sub(BigInt *a, BigInt *b, BigInt *c)
{
    init(c);
    if(a->len<b->len||(a->len==b->len&&memcmp(a->digits,b->digits,a->len *sizeof(int))< 0))
        {return 0;}
    int borrow=0;
    for(int i=0;i<a->len;i++)
    {
        int diff=a->digits[i]-borrow-b->digits[i];
        if(diff<0)
        {
            diff+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        c->digits[c->len++]=diff;
    }
    while(c->len>1&&c->digits[c->len-1]==0)
    {
        c->len--;
    }
    return 1;
}

int main()
{
    char a[MAX_LEN],b[MAX_LEN];
    BigInt A,B,C;
    while(scanf("%s%s",a,b)!=EOF)
    {
        assign(&A, a);
        assign(&B, b);
        sub(&A,&B,&C);
        print(&C);
    }
    return 0;
}
