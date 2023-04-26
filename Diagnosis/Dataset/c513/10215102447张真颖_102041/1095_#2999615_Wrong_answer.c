#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnt;
    char v[1001];
}BIGINT;
int cmp(BIGINT x,BIGINT y)
{
    if(x.cnt<y.cnt) return -1;
    else if(x.cnt>y.cnt) return 1;
    else
    {
        for(int i=x.cnt-1;i>=0;i--)
        {
            if(x.v[i]>y.v[i]) return 1;
            else if(x.v[i]<y.v[i]) return -1;
        }
        return 0;
    }
}
BIGINT Assign(BIGINT x)
{
    BIGINT r;
    r.cnt=x.cnt;
    for(int i=0;i<r.cnt;i++)
        r.v[i]=x.v[i];
    return r;
}
BIGINT sub(BIGINT x,BIGINT y)
{
    BIGINT re;
    re.cnt=0;
    re.v[0]=0;
    if(x.v[x.cnt-1]!='-'&&y.v[y.cnt-1]=='-'||x.v[x.cnt-1]=='-'&&y.v[y.cnt-1]!='-')
    {
        int carry=0,sign=0;
        if(x.v[x.cnt-1]=='-'&&y.v[y.cnt-1]!='-')
        {
            x.cnt-=1;
            sign=-1;
        }
        else if(x.v[x.cnt-1]!='-'&&y.v[y.cnt-1]=='-')
        {
            y.cnt-=1;
        }
        for(;re.cnt<x.cnt&&re.cnt<y.cnt;re.cnt++)
        {
            int t=carry+x.v[re.cnt]+y.v[re.cnt]-'0'-'0';
            re.v[re.cnt]=t%10+'0';
            carry=t/10;
        }
        while(re.cnt<x.cnt)
        {
            int t=carry+x.v[re.cnt]-'0';
            re.v[re.cnt++]=t%10+'0';
            carry=t/10;
        }
        while(re.cnt<y.cnt)
        {
            int t=carry+y.v[re.cnt+1]-'0';
            re.v[re.cnt++]=t%10+'0';
            carry=t/10;
        }
        if(carry)
            re.v[re.cnt++]=carry+'0';
        if(sign)
            re.v[re.cnt++]='-';
    }
    else
    {

            int sign=0;
            if(x.v[x.cnt-1]=='-'&&y.v[x.cnt-1]=='-')
            {
                BIGINT t=Assign(x);
                x=Assign(y);
                y=Assign(t);
                y.cnt-=1;
                x.cnt-=1;
            }
            if(cmp(x,y)<0)
            {
                BIGINT t=Assign(x);
                x=Assign(y);
                y=Assign(t);
                sign=-1;
            }
            int cheat=0;
            for(;re.cnt<y.cnt;re.cnt++)
            {
                int t=x.v[re.cnt]-y.v[re.cnt]-cheat;
                if(t<0)
                {
                    t+=cheat*10;
                    cheat=1;
                }
                re.v[re.cnt]=t+'0';
            }
            while(re.cnt<x.cnt)
            {
                int t=x.v[re.cnt]-cheat;
                if(t<0)
                {
                    t+=cheat*10;
                    cheat=1;
                }
                re.v[re.cnt++]=t;
            }
            if(sign==-1)
                re.v[re.cnt++]='-';

    }
    return re;
}

int main()
{
    char s[1000]={0};
    char t[4000]={0};
    scanf("%s",s);
    for(int i=2;i<strlen(s);i++)
    {
        char st[5]={0};
        int tmp=s[i]>='A'?s[i]-'A'+10:s[i]-'0';
        for(int i=3;i>=0;i--)
        {
            st[i]=tmp%2+'0';
            tmp/=2;
        }
        strcat(t,st);
    }
    BIGINT qr,qi,a,b;
    qr.cnt=1,qi.cnt=1,a.cnt=1,b.cnt=1;
    qr.v[0]='0',qi.v[0]='0',a.v[0]='0',b.v[0]='0';
    for(int i=0;i<strlen(t);i++)
    {
        BIGINT r;
        r.cnt=1,r.v[0]=t[i];
        a=sub(sub(r,qi),qr);
        b=sub(qr,qi);
        qr=Assign(a);
        qi=Assign(b);
    }
    if(qr.cnt==1&&qr.v[0]=='0')
    {
        if(qi.cnt==1&&qi.v[0]=='0') printf("0");
        else if(qi.cnt==2&&qi.v[0]=='1'&&qi.v[1]=='-') printf("-i");
        else if(qi.cnt==1&&qi.v[0]=='1') printf("i");
        else
        {
            for(int i=qi.cnt-1;i>=0;i--)
               printf("%c",qi.v[i]);
            printf("i");
        }

    }
    else
    {
        for(int i=qr.cnt-1;i>=0;i--)
            printf("%c",qr.v[i]);
        if(qi.cnt==2&&qi.v[0]=='1'&&qi.v[1]=='-') printf("-i");
        else if(qi.cnt==1&&qi.v[0]=='1') printf("+i");
        else if(qi.cnt==1&&qi.v[0]=='0');
        else if(qi.v[qi.cnt-1]!='-')
        {
            printf("+");
            for(int i=qi.cnt-1;i>=0;i--)
                printf("%c",qi.v[i]);
            printf("i");
        }
        else
        {
            for(int i=qi.cnt-1;i>=0;i--)
                printf("%c",qi.v[i]);
            printf("i");
        }
    }
    return 0;
}
