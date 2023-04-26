#include <stdio.h>
#include <string.h>
typedef struct{int cnt,sign,v[200];} BIGINT;

BIGINT INPUT1()
{
    BIGINT A={0,1,{0}};
    char s[200];
    gets(s);
    char* p=s;
    while(*p)
    {
        if(*p=='-')
        {
            p++;
            A.sign=-1;
        }
        else
        {
           A.v[A.cnt++]=*p-'0';
           p++;
        }

    }
    return A;
}

int cmp(BIGINT A,BIGINT B)
{
    if(A.sign*B.sign==-1)
    {
        if(A.sign==1)
        {
            return 1;
        }
        else return -1;
    }
    else if(A.sign==1)
    {
        if(A.cnt<B.cnt)
        {
            return -1;
        }
        else if(A.cnt>B.cnt)return 1;
        else
        {
            for(int i=0;i<A.cnt;i++)
            {
                if(A.v[i]==B.v[i])continue;
                else if(A.v[i]<B.v[i])return -1;
                else return 1;
            }
        }
    }
    else
    {
        if(A.cnt<B.cnt)
        {
            return 1;
        }
        else if(A.cnt>B.cnt)return -1;
        else
        {
            for(int i=0;i<A.cnt;i++)
            {
                if(A.v[i]==B.v[i])continue;
                else if(A.v[i]<B.v[i])return 1;
                else return -1;
            }
        }
    }
}

BIGINT MINUS(BIGINT A,BIGINT B)
{
    BIGINT C={0,1,{0}};
    if(B.sign==-1)
    {
        int i;
        if(A.cnt<B.cnt)
        {
            C.cnt=B.cnt+1;
            for(i=0;i<A.cnt;i++)
            {
                C.v[C.cnt-1-i]=A.v[A.cnt-1-i]+B.v[B.cnt-1-i];
            }
            for(i;i<B.cnt;i++)
            {
                C.v[C.cnt-1-i]=B.v[A.cnt-1-i];
            }
        }
        else
        {
            C.cnt=A.cnt+1;
            for(i=0;i<B.cnt;i++)
            {
                C.v[C.cnt-1-i]=A.v[A.cnt-1-i]+B.v[B.cnt-1-i];
            }
            for(i;i<A.cnt;i++)
            {
                C.v[C.cnt-1-i]=A.v[A.cnt-1-i];
            }

        }
        for(int i=C.cnt-1;i>=0;i--)
        {
            if(C.v[i]>9)
            {
                C.v[i]-=10;
                C.v[i-1]++;
            }
        }


    }
    else
    {
        C.cnt=A.cnt;
        int i;
        for(i=0;i<B.cnt;i++)
        {
            C.v[A.cnt-1-i]=A.v[A.cnt-1-i]-B.v[B.cnt-1-i];
        }
        for(i;i<A.cnt;i++)
        {
            C.v[A.cnt-1-i]=A.v[A.cnt-1-i];
        }
        for(int i=A.cnt-1;i>=0;i--)
        {
            if(C.v[i]<0)
            {
                C.v[i]+=10;
                C.v[i-1]--;
            }
        }

    }
    return C;
}

int main()
{
    int n,i=0;
    scanf("%d\n",&n);
    n=n-2;
    BIGINT MAX,temp,ANS;
    BIGINT MIN,T;
    MAX=INPUT1();
    MIN=INPUT1();
    if(cmp(MAX,MIN)==-1)
    {
        temp=MIN;
        MIN=MAX;
        MAX=temp;
    }
    while(n--)
    {
        T=INPUT1();
        if(cmp(MAX,T)==-1)
        {
            MAX=T;
        }
        else if(cmp(T,MIN)==-1)
        {
            MIN=T;
        }
    }
    ANS=MINUS(MAX,MIN);
    for(i;i<ANS.cnt;i++)
    {
        if(ANS.v[i]!=0)break;
    }
    for(i;i<ANS.cnt;i++)
    {
        printf("%d",ANS.v[i]);
    }

}
