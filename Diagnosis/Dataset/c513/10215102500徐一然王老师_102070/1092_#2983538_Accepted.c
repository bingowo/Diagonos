#include <stdio.h>
#include <string.h>

typedef struct { int cnt,v[10000]; } BIGINT ;

BIGINT int2BIG(int x)  //int 转换成BIGINT
{
    BIGINT R= {0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}

BIGINT mul(BIGINT S,int T)     //两个大整数相乘

{
    BIGINT R= {S.cnt+1,{0}};
    for (int i=0; i<1; i++)
    {
         int t,k,j;
        int carry=0;
        for (j=0; j<S.cnt; j++)
        {
            t=S.v[j]*T+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[S.cnt+1-1]==0) R.cnt--; //最高位0不统计在一个大整数的位数中
    return R;
}

int main()
{
    char s[2001];
    scanf("%s",s);
    char *p=s;
    BIGINT R;
    R=int2BIG(1);
    if(strlen(s)==1)
    {
        printf("1");
        return 0;
    }
    while(*p)
    {
        if(p==s)
        {
            if(*(p+1)==*p)
                R=int2BIG(1);
            else
                R=int2BIG(2);
        }
        else if(*(p+1)=='\0')
        {
            if(*(p-1)==*p)
                R=R;
            else
                R=mul(R,2);
        }
        else
        {
            if(*(p-1)==*p)
            {
                if(*(p+1)==*p)
                {
                    R=R;
                }
                else
                {
                    R=mul(R,2);
                }
            }
            else
            {
                if(*(p+1)==*p||*(p+1)==*(p-1))
                {
                    R=mul(R,2);
                }
                else
                {
                    R=mul(R,3);
                }
            }
        }
        p++;
    }
    for(int i=R.cnt-1;i>=0;i--)
    {
        printf("%d",R.v[i]);
    }
}
