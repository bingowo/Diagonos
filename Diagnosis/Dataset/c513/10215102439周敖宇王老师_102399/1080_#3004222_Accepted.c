#include<stdio.h>
#include<string.h>
typedef struct
{
    int l;
    int v[350];
}bigint;

bigint StringToTen(char* s)
{
    bigint rt={0,{0}};
    int l=strlen(s);
    rt.l=l;
    while(*s!='\0')
    {
        rt.v[--l]=*s-'0';
        s++;
    }
    return rt;
}

void Div2(bigint *x)
{
    int carry=0,i,t;
    if(x->v[x->l-1]<2)
    {
        x->l--;
        carry=1;
    }  
    for(i=x->l-1;i>=0;i--)
    {
        t=carry*10+x->v[i];
        carry=t%2;
        x->v[i]=t/2;
    }
}

bigint ToTwo(bigint x)
{
    bigint rt={0,{0}};
    while(x.l>0)
    {
        rt.v[rt.l++]=x.v[0]%2;
        Div2(&x);
    }
    return rt;
}

void Mul2Add(bigint *x,int d)
{
    int carry=d,i,t;
    for(i=0;i<x->l;i++)
    {
        t=x->v[i]*2+carry;
        x->v[i]=t%10;
        carry=t/10;
    }
    while(carry>0)
    {
        x->v[i]+=carry%10;
        carry/=10;
        i++;
    }
    if(i>x->l)  x->l=i;
}

bigint ToTen(bigint x)
{
    bigint rt={1,{0}};
    for(int i=0;i<x.l;i++)
    {
        Mul2Add(&rt,x.v[i]);
    }
    return rt;
}

int main()
{
    char s[120];
    int i,j,T;
    bigint n2,n10;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        n10=StringToTen(s);
        n2=ToTwo(n10);
        n10=ToTen(n2);
        printf("case #%d:\n",i);
        for(j=n10.l-1;j>=0;j--)  printf("%d",n10.v[j]);
        printf("\n");
    }
    return 0;
}