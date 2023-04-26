#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[130];
    int zhi[130];
    int wei;
    int sign;
}bigint;

int jud(bigint a,bigint b)
{
    if(a.sign==b.sign)
    {
        if(a.sign==1)
        {
            if(a.wei>b.wei) return 1;
            else if(a.wei<b.wei) return 0;
            else
            {
                int i;
                for(i=0;i<a.wei;i++)
                {
                    if(a.zhi[i]>b.zhi[i]) return 1;
                    else if(a.zhi[i]<b.zhi[i]) return 0;
                }
                return 1;
            }
        }
        else
        {
            if(a.wei>b.wei) return 0;
            else if(a.wei<b.wei) return 1;
            else
            {
                int i;
                for(i=0;i<a.wei;i++)
                {
                    if(a.zhi[i]>b.zhi[i]) return 0;
                    else if(a.zhi[i]<b.zhi[i]) return 1;
                }
                return 1;
            }
        }
    }
    else
    {
        if(a.sign==1) return 1;
        else return 0;
    }
}

bigint findmin(bigint x[],int sum)
{
    bigint re;
    int i;
    re=x[0];
    for(i=1;i<sum;i++)
    {
        if(jud(re,x[i])) re=x[i];
    }
    return re;

}

bigint findmax(bigint x[],int sum)
{
    bigint re;
    int i;
    re=x[0];
    for(i=1;i<sum;i++)
    {
        if(jud(x[i],re)) re=x[i];
    }
    return re;
}

bigint jianpu(bigint a,bigint b)
{
    bigint re;
    int j,i;
    re.sign=1;
    memset(re.zhi,0,sizeof(int)*130);
    for(i=0;(i<a.wei)||(i<b.wei);i++)
    {
        if(a.zhi[i]>=b.zhi[i]) {re.zhi[i]=a.zhi[i]-b.zhi[i];/*if((re.shu[i]==0)&&(i==(a.wei-1))&&(a.wei>1)) a.wei--;*/}
        else
        {
            re.zhi[i]=a.zhi[i]+10-b.zhi[i];
            for(j=i+1;j<a.wei;j++)
            {
                if(a.zhi[j]==0) a.zhi[j]=9;
                else
                    {
                        a.zhi[j]--;
                        if((a.zhi[j]==0)&&(j==(a.wei-1))&&(a.wei>1)) a.wei--;
                        break;
                    }
            }
        }

    }
    re.sign=1;
    re.wei=a.wei;
    while(re.zhi[re.wei-1]==0) re.wei--;
    if(re.wei<=0) re.wei=1;
    return re;
}

bigint jia(bigint a,bigint b)
{
    int i,du,jin=0;
    bigint re;
    memset(re.zhi,0,sizeof(int)*130);
    for(i=0;(i<a.wei)||(i<b.wei)||(jin!=0);i++)
    {
        du=a.zhi[i]+b.zhi[i]+jin;
        re.zhi[i]=du%10;
        jin=du/10;
    }
    re.wei=i;
    return re;
}

bigint distance(bigint a,bigint b)
{
    bigint re;
    if((a.sign==1)&&(b.sign==1))
    {
        re=jianpu(a,b);
        re.sign=a.sign;
    }
    else if((a.sign==-1)&&(b.sign==-1))
    {
        re=jianpu(b,a);
        re.sign=1;
    }
    else
    {
        re=jia(a,b);
        re.sign=1;
    }
    return re;
}

bigint reverse(bigint a)
{
    int i,c;
    for(i=0;i<(a.wei/2);i++)
    {
        c=a.zhi[i];
        a.zhi[i]=a.zhi[a.wei-i-1];
        a.zhi[a.wei-1-i]=c;
    }
    return a;
}

int main()
{
    int i,n;
    scanf("%d",&n);
    bigint x[55],re;
    for(i=0;i<55;i++)
    {
        memset(x[i].zhi,0,sizeof(int)*130);
    }
    for(i=0;i<n;i++)
    {
        int j,len;
        scanf("%s",x[i].s);
        len=strlen(x[i].s);
        if(x[i].s[0]=='-')
        {
            x[i].sign=-1;
            for(j=1;j<len;j++)
            {
                x[i].zhi[j-1]=x[i].s[j]-'0';
            }
            x[i].wei=len-1;
        }
        else
        {
            x[i].sign=1;
            for(j=0;j<len;j++)
            {
                x[i].zhi[j]=x[i].s[j]-'0';
            }
            x[i].wei=len;
        }
    }
    bigint small,large;
    small=findmin(x,n);
    large=findmax(x,n);

    /*printf("min=%s\n",small.s);
    printf("min:sign=%d,wei=%d\n",small.sign,small.wei);
    printf("max=%s\n",large.s);
    printf("max:sign=%d,wei=%d\n",large.sign,large.wei);*/

    large=reverse(large);
    small=reverse(small);

    re=distance(large,small);

    re=reverse(re);
    //printf("re=");
    for(i=0;i<re.wei;i++) printf("%d",re.zhi[i]);


    return 0;

}
