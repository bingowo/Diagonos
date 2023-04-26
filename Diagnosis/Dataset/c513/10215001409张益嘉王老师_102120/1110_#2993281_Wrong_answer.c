#include <stdio.h>
#include <stdlib.h>

long long numof(int st,int en,char sign,char *s)
{
    int i,j,len=strlen(s);
    long long re=0;
    if(st>en) return 1;
    for(i=st;i<=en;i++)
    {
        if(s[i]==sign) return 0;
        re*=10;
        re+=s[i]-'0';
    }
    /*for(i=st;i<=en;i++)
    {
        printf("s[%d]=%c  ",i,s[i]);
    }
    printf("\n");*/
    return re;
}

long long xishu(char s[],char sign)
{
    int i,len,j,st;
    len=strlen(s);
    long long re=0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='=') break;
        if((s[i]==sign)&&(i>0))
        {
            for(j=i-1;j>=0;j--)
            {
                if(s[j]=='+') {re+=numof(j+1,i-1,sign,s);break;}
                else if(s[j]=='-') {re-=numof(j+1,i-1,sign,s);break;}
            }
            if((j==-1)&&(s[0]<='9')&&(s[0]>='0')) re+=numof(0,i-1,sign,s);
        }
        else if((s[i]==sign)&&(i==0)) re+=1;
        //printf("in xishu:re=%lld\n",re);
    }
    st=i+1;
    for(i=st;i<len;i++)
    {
        if((s[i]==sign)&&(i>0))
        {
            for(j=i-1;j>=st;j--)
            {
                if(s[j]=='+') {re-=numof(j+1,i-1,sign,s);break;}
                else if(s[j]=='-') {re+=numof(j+1,i-1,sign,s);break;}
            }
            if((j==st-1)&&(s[st]<='9')&&(s[st]>='0')) re-=numof(st,i-1,sign,s);
        }
        else if((s[i]==sign)&&(i==st)) re-=1;
        //printf("in xishu,denghaohou:re=%lld\n",re);
    }
    return re;
}

long long qiuzhi(char *s,char sign)
{
    int i,len,j,st;
    len=strlen(s);
    long long re=0;
    for(i=0;i<len;i++)
    {

        if(((s[i]=='+')||(s[i]=='-')||(s[i]=='='))&&(i>0))
        {
            for(j=i-1;j>=0;j--)
            {
                if(s[j]=='+') {re-=numof(j+1,i-1,sign,s);break;}
                else if(s[j]=='-') {re+=numof(j+1,i-1,sign,s);break;}
            }
            if((j==-1)&&(s[0]<='9')&&(s[0]>='0')) re-=numof(0,i-1,sign,s);
        }
        else if((s[i]=='-')&&(i==0)) re+=1;
        if(s[i]=='=') break;
    }
    st=i+1;
    for(i=st;i<len+1;i++)
    {
        if(((s[i]=='+')||(s[i]=='-')||(i==len))&&(i>0))
        {
            for(j=i-1;j>=st;j--)
            {
                if(s[j]=='+') {re+=numof(j+1,i-1,sign,s);break;}
                else if(s[j]=='-') {re-=numof(j+1,i-1,sign,s);break;}
            }
            if((j==st-1)&&(s[st]<='9')&&(s[st]>='0')) re+=numof(st,i-1,sign,s);
        }
        else if((s[i]=='-')&&(i==st)) re-=1;
    }
    return re;
}

int main()
{
    char s[90];
    scanf("%s",s);
    long long xi,zhi;
    double jie;
    char sign;
    int len=strlen(s),i;
    for(i=0;i<len;i++)
    {
        if((s[i]>='a')&&(s[i]<='z')) {sign=s[i];break;}
    }

    xi=xishu(s,sign);
    zhi=qiuzhi(s,sign);
    //printf("xishu=%d\n",xi);
    //printf("zhi=%d\n",zhi);
    if(zhi==0) jie=0;
    else jie=(double)zhi/xi;

    printf("%c=%.3lf",sign,jie);
}
