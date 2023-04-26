#include <stdio.h>

typedef struct{int cnt,v[500];} BIGINT;
int sign=1;
BIGINT INPUT1()
{
    BIGINT A={0,{0}};
    char c;
    while((c=getchar())!=' '&&c!=EOF)
    {
        A.v[A.cnt++]=c-'0';
    }
    return A;
}

BIGINT INPUT2()
{
    BIGINT B={0,{0}};
    char c;
    while((c=getchar())!='\n'&&c!=EOF)
    {
        B.v[B.cnt++]=c-'0';
    }
    return B;
}

BIGINT MINUS(BIGINT A,BIGINT B)
{
    BIGINT R={0,{0}};
    int flag;
    if(A.cnt>B.cnt)
    {
        flag=1;
    }
    else if(A.cnt<B.cnt)
    {
        flag=0;
    }
    else
    {
        for(int i=0;i<A.cnt;i++)
        {
            if(A.v[i]<B.v[i])
            {
                flag=0;break;
            }
            else if(A.v[i]>B.v[i])
            {
                flag=1;break;
            }
        }

    }
    if(flag==1)
    {
        R.cnt=A.cnt;
        for(int i=0;i<R.cnt;i++)
        {
            if(i<B.cnt)
            {
                R.v[R.cnt-1-i]=A.v[A.cnt-1-i]-B.v[B.cnt-1-i];
            }
            else
            {
                R.v[R.cnt-1-i]=A.v[A.cnt-1-i];
            }

        }
        for(int i=R.cnt;i>=0;i--)
        {
            if(R.v[i]<0)
            {
                R.v[i]=R.v[i]+10;
                R.v[i-1]--;
            }
        }
    }
    else
    {
        sign=-1;
        R.cnt=B.cnt;
        for(int i=0;i<R.cnt;i++)
        {
            if(i<A.cnt)
            {
                R.v[R.cnt-1-i]=B.v[B.cnt-1-i]-A.v[A.cnt-1-i];
            }
            else
            {
                R.v[R.cnt-1-i]=B.v[B.cnt-1-i];
            }

        }
        for(int i=R.cnt;i>=0;i--)
        {
            if(R.v[i]<0)
            {
                R.v[i]=R.v[i]+10;
                R.v[i-1]--;
            }
        }
    }
    return R;
}

int main()
{
    while(1)
    {
        BIGINT A;
        BIGINT B;
        BIGINT R;
        A=INPUT1();
        B=INPUT2();
        R=MINUS(A,B);
        if(sign==-1)
        {
            sign=1;
            printf("-");
        }
        int i=0;
        for(i;i<R.cnt-1;i++)
        {
            if(R.v[i]!=0)break;
        }
        for(i;i<R.cnt-1;i++)
        {
            printf("%d",R.v[i]);
        }
        printf("%d\n",R.v[R.cnt-1]);
    }

}
