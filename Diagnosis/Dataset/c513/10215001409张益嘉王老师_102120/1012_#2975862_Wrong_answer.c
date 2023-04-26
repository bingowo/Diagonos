#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long long shibu;
    long long xubu;
}fushu;

void reverse(int re[],int wei)
{
    int i;
    for(i=0;i<wei/2;i++)
    {
        int m;
        m=re[i];
        re[i]=re[wei-1-i];
        re[wei-1-i]=m;
    }
}

long long jdz(long long x)
{
    if(x>=0) return x;
    else return -x;
}

long long a2i(char *s,int st,int en)
{
    int i;
    if(st>en) return 0;
    long long re=0;
    if(s[st]=='-')
    {
        if(st==en) re=1;
        for(i=st+1;i<=en;i++)
        {
            re*=(long long)10;
            re+=(long long)(s[i]-'0');
        }
        re=-re;
    }
    else
    {
        if(s[st]=='+')
        {
            if(st==en) re=1;
            for(i=st+1;i<=en;i++)
            {
                re*=(long long)10;
                re+=(long long)(s[i]-'0');
            }
        }
        else
        {
            for(i=st;i<=en;i++)
            {
                re*=(long long)10;
                re+=(long long)(s[i]-'0');
            }
        }
    }
    return re;

}

fushu zhuanhua(char *s)
{
    int len,i,j;
    fushu re;
    len=strlen(s);

    if(s[len-1]=='i')
    {
        if(len==1)
        {
            re.shibu=0;
            re.xubu=1;
        }
        /*else if((len==2)&&(s[0]=='-'))
        {
            re.shibu=0;
            re.xubu=-1;
        }*/
        else
        {
            for(j=len-1;j>=0;j--)
            {
                if((s[j]=='+')||(s[j]=='-'))
                {
                    re.xubu=a2i(s,j,len-2);
                    re.shibu=a2i(s,0,j-1);
                    break;
                }
                else
                {
                    re.shibu=0;
                    re.xubu=a2i(s,0,len-2);
                }

            }
        }
    }
    else
    {
        re.shibu=a2i(s,0,len-1);
        re.xubu=0;
    }

    return re;
}

fushu chu(fushu c,int yu)
{
    fushu re;
    c.shibu-=(long long)yu;
    c.xubu+=(long long)yu;
    re.shibu=(long long)(c.xubu-c.shibu);
    re.xubu=(long long)-(c.shibu+c.xubu);
    if(re.shibu>=0) re.shibu=(long long)re.shibu/2;
    else re.shibu=(long long)-(jdz(re.shibu)/2);
    if(re.xubu>=0) re.xubu=(long long) re.xubu/2;
    else re.xubu=(long long)-(jdz(re.xubu))/2;

    return re;

}

int main()
{
    char s[100];
    scanf("%s",s);
    int i,j,n=0;
    fushu c;
    c=zhuanhua(s);
    //printf("test:c.shibu=%lld,c.xubu=%lld\n",c.shibu,c.xubu);
    int ans[1000];
    while((c.shibu)||(c.xubu))
    {
        ans[n]=(jdz(c.shibu)+jdz(c.xubu))%2;
        c=chu(c,ans[n]);
        n++;
    }
    reverse(ans,n);
    for(i=0;i<n;i++) printf("%d",ans[i]);

    return 0;


}
