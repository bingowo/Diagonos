#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnt;
    int v[1001];
    int sign;
}BIGINT;
BIGINT Assign(BIGINT x)
{
    BIGINT r;
    r.cnt=x.cnt;
    for(int i=0;i<r.cnt;i++)
        r.v[i]=x.v[i];
    r.sign=x.sign;
    return r;
}
void Print(BIGINT qr,BIGINT qi)
{
    if(qr.cnt==1&&qr.v[0]==0)
    {
        if(qi.cnt==1&&qi.v[0]==0) printf("0");
        else if(qi.cnt==1&&qi.v[0]==1&&qi.sign==-1) printf("-i");
        else if(qi.cnt==1&&qi.v[0]==1&&qi.sign==1) printf("i");
        else
        {
            if(qi.sign==-1)
                printf("-");
            for(int i=qi.cnt-1;i>=0;i--)
               printf("%d",qi.v[i]);
            printf("i");
        }

    }
    else
    {
        if(qr.sign==-1) printf("-");
        for(int i=qr.cnt-1;i>=0;i--)
            printf("%d",qr.v[i]);
        if(qi.cnt==1&&qi.v[0]==1&&qi.sign==-1) printf("-i");
        else if(qi.cnt==1&&qi.v[0]==1&&qi.sign==1) printf("+i");
        else if(qi.cnt==1&&qi.v[0]==0);
        else
        {
            if(qi.sign==1)
                printf("+");
            else printf("-");
            for(int i=qi.cnt-1;i>=0;i--)
                printf("%d",qi.v[i]);
            printf("i");
        }
    }
}
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
void Sub(BIGINT* re,BIGINT x,BIGINT y)
{
    int cheat=0;
    for(;re->cnt<y.cnt;re->cnt++)
    {
        int t=x.v[re->cnt]-y.v[re->cnt]-cheat;
        if(t<0)
        {
            t+=10;
            cheat=1;
        }
        else cheat=0;
        re->v[re->cnt]=t;
    }
    while(re->cnt<x.cnt)
    {
        int t=x.v[re->cnt]-cheat;
        if(t<0)
        {
            t+=10;
            cheat=1;
        }
        else cheat=0;
        re->v[re->cnt++]=t;
    }
    for(int i=re->cnt-1;i>=0&&re->v[i]==0;i--) re->cnt--;
}
BIGINT sub(BIGINT x,BIGINT y)
{
    BIGINT re={0,{0},1};
    if(x.cnt==1&&x.v[0]==0)
    {
        y.sign=y.sign*(-1);
        return y;
    }
    else if(y.cnt==1&&y.v[0]==0)
    {
        return x;
    }
    if(x.sign*y.sign<0)
    {
        if(x.sign==-1)
            re.sign=-1;
        int carry=0;
        for(;re.cnt<x.cnt&&re.cnt<y.cnt;re.cnt++)
        {
            int t=carry+x.v[re.cnt]+y.v[re.cnt];
            re.v[re.cnt]=t%10;
            carry=t/10;
        }
        while(re.cnt<x.cnt)
        {
            int t=carry+x.v[re.cnt];
            re.v[re.cnt++]=t%10;
            carry=t/10;
        }
        while(re.cnt<y.cnt)
        {
            int t=carry+y.v[re.cnt];
            re.v[re.cnt++]=t%10;
            carry=t/10;
        }
        if(carry)
            re.v[re.cnt++]=carry;
    }
    else
    {
        if(x.sign==-1)
        {
            if(cmp(x,y)<0)
            {
                Sub(&re,y,x);
            }
            else if(cmp(x,y)>0)
            {
                re.sign=-1;
                Sub(&re,x,y);
            }
            else
            {
                re.v[0]=0;
                re.cnt=1;
            }
        }
        else
        {
            if(cmp(x,y)<0)
            {
                re.sign=-1;
                Sub(&re,y,x);
            }
            else if(cmp(x,y)>0)
            {
                Sub(&re,x,y);
            }
            else
            {
                re.v[0]=0;
                re.cnt=1;
            }
        }
    }
    return re;
}

int main()
{
    char s[2000]={0};
    char t[8000]={0};
    scanf("%s",s);
    for(int i=2;i<strlen(s);i++)
    {
        char st[5]={0};
        int tmp=(s[i]>='A')?s[i]-'A'+10:s[i]-'0';
        for(int i=3;i>=0;i--)
        {
            st[i]=tmp%2+'0';
            tmp/=2;
        }
        strcat(t,st);
    }
    BIGINT qr={1,{0},1},qi={1,{0},1},a={1,{0},1},b={1,{0},1};
    for(int i=0;i<strlen(t);i++)
    {
        BIGINT r={1,{t[i]-'0'},1};
        a=sub(sub(r,qi),qr);
        b=sub(qr,qi);
        qr=Assign(a);
        qi=Assign(b);
    }
    Print(qr,qi);
    return 0;
}