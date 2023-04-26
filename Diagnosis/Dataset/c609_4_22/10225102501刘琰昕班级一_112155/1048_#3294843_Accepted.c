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

/* 大数加法 */
void add(BigInt *a, BigInt *b, BigInt *c)
{
    init(c);
    int carry=0;
    for (int i=0;i<a->len||i< b->len;i++)
    {
        int sum=a->digits[i]+b->digits[i]+carry;
        c->digits[c->len++]=sum % 10;
        carry=sum/10;
    }
    if (carry)
    {
        c->digits[c->len++] = carry;
    }
}

int main()
{
    BigInt f[121];
    assign(&f[0], "0");
    assign(&f[1], "1");
    for(int i=2;i<121;i++)
        add(&f[i-2],&f[i-1],&f[i]);
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        print(&f[n]);
    }
    return 0;
}