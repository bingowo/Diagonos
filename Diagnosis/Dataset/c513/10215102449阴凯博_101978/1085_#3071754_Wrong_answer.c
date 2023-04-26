#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int digits[550];
    char sign;
    int len;
}BIGN;

BIGN pluss(BIGN* A,BIGN* B)
{
    BIGN C;
    memset(C.digits,0,sizeof(C.digits));
    if (A->sign!=B->sign)
    {
        C.sign=A->sign;
        int m=A->len>B->len?A->len:B->len;
        int carry=0;
        for (int i=0;i<m;i++)
        {
            C.digits[i]=A->digits[i]+B->digits[i]+carry;
            if (C.digits[i]>9)
            {
                C.digits[i]-=10;
                carry=1;
            }
            else
                carry=0;
        }
        if (carry)
        {
            C.digits[m]+=carry;
            m++;
        }
        C.len=m;
        return C;
    }
    else
    {
        if (A->len>B->len)
        {
            int carry=0;
            for (int i=0;i<A->len;i++)
            {
                C.digits[i]=A->digits[i]-B->digits[i]-carry;
                if (C.digits[i]<0)
                {
                    carry=1;
                    C.digits[i]+=10;
                }
                else
                    carry=0;
            }
            C.sign=A->sign;
        }
        if (A->len==B->len)
        {
            int flag=0,j=0;
            for (j=A->len-1;j>=0;j--)
            {
                if (A->digits[j]>B->digits[j])
                {
                    flag=1;
                    break;
                }
                if (A->digits[j]<B->digits[j])
                    break;
            }
            if (j==-1)
            {
                C.digits[0]=0;
                C.sign=0;
                C.len=1;
                return C;
            }
            else
            {
                if (flag==1) //A-B
                {
                    int carry=0;
                    for (int i=0;i<A->len;i++)
                    {
                        C.digits[i]=A->digits[i]-B->digits[i]-carry;
                        if (C.digits[i]<0)
                        {
                            carry=1;
                            C.digits[i]+=10;
                        }
                        else
                            carry=0;
                    }
                     C.sign=A->sign;

                }
                else
                {
                    int carry=0;
                    for (int i=0;i<A->len;i++)
                    {
                        C.digits[i]=B->digits[i]-A->digits[i]-carry;
                         if (C.digits[i]<0)
                        {
                            carry=1;
                            C.digits[i]+=10;
                        }
                        else
                            carry=0;
                    }
                    C.sign=(B->sign?0:1);

                }
            }
        }
        if (A->len<B->len)
        {
            int carry=0;
            for (int i=0;i<B->len;i++)
            {
                C.digits[i]=B->digits[i]-A->digits[i]-carry;
                if (C.digits[i]<0)
                {
                    carry=1;
                    C.digits[i]+=10;
                }
                else
                    carry=0;
            }
            C.sign=B->sign;
        }
        int k=0;
        for (k=A->len>B->len?A->len:B->len;k>=0 && C.digits[k]==0;k--);
        C.len=k+1;
        return C;
    }
}


int main()
{
    char s1[550]={0};  char s2[550]={0};
    while (scanf("%s %s",s1,s2)!=EOF)
    {
        BIGN A,B,C;
        A.sign=0; B.sign=0; C.sign=0;
        A.len=0; B.len=0; C.len=0;
        memset(A.digits,0,sizeof(A.digits));
        memset(B.digits,0,sizeof(B.digits));
        if (s1[0]=='-') A.sign=1;
        if (s2[0]=='-') B.sign=1;
        for (int i=strlen(s1)-1;i>=0;i--)
        {
            if (isdigit(s1[i]))
                A.digits[A.len++]=s1[i]-'0';
        }
        for (int i=strlen(s2)-1;i>=0;i--)
        {
            if (isdigit(s2[i]))
                B.digits[B.len++]=s2[i]-'0';
        }
        C=pluss(&A,&B);
        if (C.sign)
            printf("-");
        for (int i=C.len-1;i>=0;i--)
            printf("%d",C.digits[i]);

    }



    return 0;
}
