#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXD 1020
#include <ctype.h>

typedef struct
{
    char digit[MAXD];
    int size;
    int sign;
}BIGN;

typedef struct
{
    BIGN r;
    BIGN f;
}NUM;


BIGN ADD(BIGN m,BIGN n)
{
    BIGN ret;
    int carry=0;
    for (int i=0;i<MAXD;i++)
        ret.digit[i]='0';
    ret.size=0;
    if (m.sign ^ n.sign) //sign diff
    {
        if (n.size>m.size || (m.size==n.size && m.digit[m.size-1]<n.digit[n.size-1]))
            return ADD(n,m);
        else
        {
            ret.size=m.size;
            ret.sign=m.sign;
            for (int i=0;i<n.size;i++)
            {
                int mm=m.digit[i]-'0';
                int nn=n.digit[i]-'0';
                int diff=mm-nn-carry;
                ret.digit[i]=(diff+10)%10+'0';
                carry=diff<0?1:0;
            }
            for (int i=n.size;i<m.size;i++)
            {
                int mm=m.digit[i]-'0';
                int diff=mm-carry;
                ret.digit[i]=(diff+10)%10+'0';
                carry=diff<0?1:0;
            }
            while (ret.digit[ret.size-1]=='0')
                ret.size--;
            if (ret.size==0)
            {
                ret.sign=1;
                ret.size=1;
            }
            return ret;

        }
    }
    else
    {
        ret.sign=m.sign;
        if (m.size<n.size)
            return ADD(n,m);
        else
        {
            ret.size=m.size;
            for (int i=0;i<m.size;i++)
            {
                int mm=m.digit[i]-'0';
                if (i>=n.size)  n.digit[i]='0';
                int nn=n.digit[i]-'0';
                int sum=mm+nn;
                ret.digit[i]=(sum+carry)%10+'0';
                carry=sum/10;
            }
            if (carry)
            {
                ret.size++;
                ret.digit[m.size]=carry+'0';
            }
            while (ret.digit[ret.size-1]=='0')
                ret.size--;
            return ret;
        }
    }
}

BIGN MINUS(BIGN m,BIGN n)
{
    n.sign=!n.sign;
    return ADD(m,n);
}

void print(BIGN r)
{
    printf(r.sign?"":"-");
    for (int i=r.size-1;i>=0;i--)
        printf("%c",r.digit[i]);
}

BIGN multiply(BIGN m,BIGN n)
{
    BIGN ret;
    int carry=0;
    for (int i=0;i<MAXD;i++)
        ret.digit[i]='0';
    ret.size=m.size+n.size;
    ret.sign=!(m.sign^n.sign);
    for (int i=0;i<m.size;i++)
    {
        BIGN tmp;
        for (int i=0;i<MAXD;i++)
            tmp.digit[i]='0';
        tmp.size=m.size+n.size;
        tmp.sign=!(m.sign^n.sign);
        for (int j=0;j<n.size;j++)
        {
            int mm=m.digit[i]-'0';
            int nn=n.digit[j]-'0';
            int sum=mm*nn+carry;
            tmp.digit[i+j]=sum%10+'0';
            carry=sum/10;
        }
        tmp.digit[i+n.size]=carry+'0';
        ret=ADD(ret,tmp);
    }
    while (ret.digit[ret.size-1]=='0')
        ret.size--;
    if (ret.size==0)
    {
        ret.size=1;
        ret.sign=1;
    }
    return ret;
}

NUM mul(NUM a,NUM b)
{
    NUM n;
    n.f=ADD(multiply(a.r,b.f),multiply(b.r,a.f));
    n.r=MINUS(multiply(a.r,b.r),multiply(b.f,a.f));
    return n;
}

NUM pwr(BIGN a)
{
    NUM n,m;
    m.f.digit[0]='1'; m.f.sign=1; m.f.size=1;
    m.r.digit[0]='1'; m.r.sign=0; m.r.size=1;
    n.f.digit[0]='0'; n.f.sign=1; n.f.size=1;
    n.r.digit[0]='1'; n.r.sign=1; n.r.size=1;
    BIGN i;
    i.digit[0]='1'; i.sign=1; i.size=1;
    while (1)
    {
        if (a.digit[0]=='0' && a.size==1)
            break;
        a=MINUS(a,i);
        n=mul(n,m);
    }

    return n;
}

BIGN get(char* s)
{
    int i,j;
    BIGN ret;
    if (s[0]=='-')
    {
        ret.sign=0;
        ret.size=strlen(s)-1;
    }
    else
    {
        ret.sign=1;
        ret.size=strlen(s);
    }
    for (i=0,j=0;j<ret.size;i++,j++)
    {
        ret.digit[j]=s[i];
    }
    return ret;

}

int main()
{
    char s[MAXD]={0};
    char arr[100000]={0};
    scanf("%s",s);
    int k=0;
    for (int i=2;i<strlen(s);i++)
    {
        int d=0;
        if (s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=0x8;
        while (flag)
        {
            if (d&flag) arr[k++]='1';
            else arr[k++]='0';
            flag=flag>>1;
        }
    }
    NUM result;
    result.f.digit[0]='0'; result.f.sign=1; result.f.size=1;
    result.r.digit[0]='0'; result.r.sign=1; result.r.size=1;


    for (int j=0;j<strlen(arr);j++)
    {
        if (arr[j]=='1')
        {
            int mm=strlen(arr)-j-1;
            char s1[MAXD]={0};
            if (mm==0)
                s1[0]='0';
            else
            {
                for (int k=0;mm;k++)
                {
                    s1[k]=mm%10+'0';
                    mm=mm/10;
                }
            }
            BIGN nn=get(s1);
            result.r=ADD(result.r,pwr(nn).r);
            result.f=ADD(result.f,pwr(nn).f);
        }
    }
    if (result.f.digit[0]=='0' && result.f.size==1)
    {
        print(result.r);
        printf("\n");
    }
    else
    {
        if (!(result.f.digit[0]=='0' && result.f.size==1))
        {
            print(result.r);
            if (result.f.sign) printf("+");
        }
        if (result.f.digit[0]=='1' && result.f.sign==1 && result.f.size==1)
            printf("i\n");
        else if (result.f.digit[0]=='1' && result.f.sign==0 && result.f.size==1)
            printf("-i\n");
        else
        {
            print(result.f);
            printf("i\n");
        }
    }

    return 0;
}
