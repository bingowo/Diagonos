#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int cnt;
    int v[5000];
    int sign;
}BIGINT;
typedef struct
{
    BIGINT r,i;
}COMPLEX;

void init(COMPLEX* data,char s[])
{
    int len=strlen(s),j=len-1;
    if(s[j]=='i')
    {
        if(len==1) {data->i.v[data->i.cnt++]=1,data->r.cnt=1,data->r.v[0]=0;return;}
        j-=1;
        if(s[j]=='-') data->i.v[data->i.cnt++]=1,data->i.sign=-1;
        else if(s[j]=='+') data->i.v[data->i.cnt++]=1,data->i.sign=1;
        else
        {
            while(s[j]!='+'&&s[j]!='-'&&j>=0)
            {
                data->i.v[data->i.cnt++]=s[j]-'0';
                j--;
            }
            if(s[j]=='+') data->i.sign=1;
            else if(s[j]=='-') data->i.sign=-1;
        }
        if(j<0||s[j]=='-'&&j==0)  {data->r.cnt=1,data->r.v[0]=0;return;}
        else
        {
            j-=1;
            while(s[j]!='-'&&j>=0)
            {
                data->r.v[data->r.cnt++]=s[j]-'0';
                j--;
            }
            if(s[j]=='-')
                data->r.sign=-1;
        }
    }
    else
    {
        data->i.v[data->i.cnt++]=0;
        while(s[j]!='-'&&j>=0)
        {
            data->r.v[data->r.cnt++]=s[j]-'0';
            j--;
        }
        if(s[j]=='-')
            data->r.sign=-1;
    }
}
BIGINT mul(BIGINT x,BIGINT y)
{
    BIGINT re={1,{0},1};
    if(x.cnt==1&&x.v[0]==0||y.cnt==1&&y.v[0]==0) return re;
    re.sign=x.sign*y.sign;
    re.cnt=x.cnt+y.cnt;
    for(int i=0;i<y.cnt;i++)
    {
        int carry=0,j;
        for(j=0;j<x.cnt;j++)
        {
            int t=x.v[j]*y.v[i]+carry+re.v[i+j];
            re.v[i+j]=t%10;
            carry=t/10;
        }
        int k=i+j;
        while(carry)
        {
            int t=re.v[k]+carry;
            re.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if(re.v[re.cnt-1]==0) re.cnt--;
    return re;
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
BIGINT add(BIGINT x,BIGINT y)
{
    BIGINT re={0,{0},1};
    if(x.sign*y.sign>0)
    {
        if(x.sign==-1) re.sign=-1;
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

int main()
{
    char s[11]={0};
    int d;
    scanf("%s%d",s,&d);
    COMPLEX data={{0,{0},1},{0,{0},1}};
    init(&data,s);
    COMPLEX rdata={{0,{0},1},{0,{0},1}};
    init(&rdata,s);
    for(int i=1;i<d;i++)
    {
        BIGINT tr1=mul(rdata.i,data.i),tr2=mul(rdata.r,data.r),ti1=mul(rdata.r,data.i),ti2=mul(rdata.i,data.r);
        rdata.i=add(ti1,ti2);
        tr1.sign*=-1;
        rdata.r=add(tr2,tr1);
    }
    Print(rdata.r,rdata.i);
    return 0;
}