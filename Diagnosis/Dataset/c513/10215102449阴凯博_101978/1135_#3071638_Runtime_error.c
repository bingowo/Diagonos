#include <stdio.h>
#include <stdlib.h>




typedef struct
{
    int digits[120];
    char sign;
    int len;
}BIGN;

BIGN pluss(BIGN* A,BIGN* B)
{
    BIGN C;
    memset(C.digits,0,sizeof(C.digits));
    if (A->sign==B->sign)
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
                    C.sign=B->sign;

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
    int n;
    scanf("%d",&n);
    BIGN F[10000];
    F[0].digits[0]=0; F[0].sign=0; F[0].len=1;
    F[1].digits[0]=1; F[1].sign=0; F[1].len=1;
    F[2].digits[0]=2; F[2].sign=0; F[2].len=1;
    F[3].digits[0]=3; F[3].sign=0; F[3].len=1;
    F[4].digits[0]=6; F[4].sign=0; F[4].len=1;
    for (int i=5;i<=n;i++)
    {
        BIGN C=pluss(&F[i-1],&F[i-2]);
        F[i]=pluss(&C,&F[i-4]);
    }
    for (int i=F[n].len-1;i>=0;i--)
        printf("%d",F[n].digits[i]);

    return 0;
}
