#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int wei;
    int shu[1100];
    int sign;
}bigint;

typedef struct
{
    bigint shibu;
    bigint xubu;
}fushu;

bigint reverse(bigint a)
{
    int i,c;
    for(i=0;i<(a.wei/2);i++)
    {
        c=a.shu[i];
        a.shu[i]=a.shu[a.wei-i-1];
        a.shu[a.wei-1-i]=c;
    }
    return a;
}

int find0(bigint a)
{
    int i;
    for(i=0;i<a.wei;i++)
    {
        if(a.shu[i]!=0) return 0;
    }
    return 1;
}

int findi(char *s)
{
    int i,len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='i') return 1;
    }
    return 0;
}

int findshibu(char*s)
{
    int i,len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='+') return 1;
    }
    for(i=len-1;i>=0;i--)
    {
        if(s[i]=='-') break;
    }
    if(i<=0) return 0;
    else return 1;


}

fushu zhuanhuan(char *s)
{
    fushu re;
    int i,j;
    memset(re.shibu.shu,0,sizeof(int)*1100);
    memset(re.xubu.shu,0,sizeof(int)*1100);

    int len=strlen(s);
    if(findi(s))
    {
        if(findshibu(s))
        {
            if(s[0]=='-')
            {
                re.shibu.sign=-1;
                for(j=1;j<len;j++)
                {
                    if((s[j]=='+')||(s[j]=='-')) break;
                    re.shibu.shu[j-1]=s[j]-'0';
                }
                re.shibu.wei=j-1;

                if(s[j]=='+')
                {
                    re.xubu.sign=1;
                    if(s[j+1]=='i') {re.xubu.shu[0]=1;re.xubu.wei=1;}
                    else
                    {
                        for(i=0,j++;j<len-1;j++,i++)
                        {
                            re.xubu.shu[i]=s[j]-'0';
                        }
                        re.xubu.wei=i;
                    }
                }
                else if(s[j]=='-')
                {
                    re.xubu.sign=-1;
                    if(s[j+1]=='i') {re.xubu.shu[0]=1;re.xubu.wei=1;}
                    else
                    {
                        for(i=0,j++;j<len-1;j++,i++)
                        {
                            re.xubu.shu[i]=s[j]-'0';
                        }
                        re.xubu.wei=i;
                    }
                }
            }
            else
            {
                re.shibu.sign=1;
                for(j=0;j<len;j++)
                {
                    if((s[j]=='+')||(s[j]=='-')) break;
                    re.shibu.shu[j]=s[j]-'0';
                }
                re.shibu.wei=j;

                if(s[j]=='+')
                {
                    re.xubu.sign=1;
                    if(s[j+1]=='i') {re.xubu.shu[0]=1;re.xubu.wei=1;}
                    else
                    {
                        for(i=0,j++;j<len-1;j++,i++)
                        {
                            re.xubu.shu[i]=s[j]-'0';
                        }
                        re.xubu.wei=i;
                    }
                }
                else if(s[j]=='-')
                {
                    re.xubu.sign=-1;
                    if(s[j+1]=='i') {re.xubu.shu[0]=1;re.xubu.wei=1;}
                    else
                    {
                        for(i=0,j++;j<len-1;j++,i++)
                        {
                            re.xubu.shu[i]=s[j]-'0';
                        }
                        re.xubu.wei=i;
                    }
                }
            }
        }
        else
        {
            re.shibu.sign=1;
            re.shibu.wei=1;
            if(s[0]=='-')
            {
                re.xubu.sign=-1;
                if((len==2)&&(s[1]=='i')) {re.xubu.shu[0]=1;re.xubu.wei=1;}
                else
                {
                    for(j=1;j<len-1;j++)
                    {
                        re.xubu.shu[j-1]=s[j]-'0';
                    }
                    re.xubu.wei=len-2;
                }
            }
            else
            {
                re.xubu.sign=1;
                if((len==1)&&(s[0]=='i')) {re.xubu.shu[0]=1;re.xubu.wei=1;}
                else
                {
                    for(j=0;j<len-1;j++)
                    {
                        re.xubu.shu[j]=s[j]-'0';
                    }
                    re.xubu.wei=len-1;
                }
            }
        }
    }
    else
    {
        re.xubu.sign=1;
        re.xubu.wei=1;
        if(s[0]=='-')
        {
            re.shibu.sign=-1;
            for(j=1;j<len;j++)
            {
                re.shibu.shu[j-1]=s[j]-'0';
            }
            re.shibu.wei=len-1;
        }
        else
        {
            re.shibu.sign=1;
            for(j=0;j<len;j++)
            {
                re.shibu.shu[j]=s[j]-'0';
            }
            re.shibu.wei=len;
        }

    }
    return re;

}

void shuchu(fushu re)
{
    int i;
    if(find0(re.xubu))
    {
        if(re.shibu.sign==1)
        {
            for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
        }
        else
        {
            printf("-");
            for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
        }
        return;
    }
    else
    {
        if(find0(re.shibu))
        {
            if(re.xubu.sign==1)
            {
                if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
            }
            else
            {
                printf("-");
                if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
            }
            printf("i");
            return;
        }
        else
        {
            if(re.shibu.sign==1)
            {
                for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
                if(re.xubu.sign==1)
                {
                    printf("+");
                    if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                    else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
                }
                else
                {
                    printf("-");
                    if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                    else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
                }
                printf("i");
            }
            else
            {
                printf("-");
                for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);
                if(re.xubu.sign==1)
                {
                    printf("+");
                    if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                    else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
                }
                else
                {
                    printf("-");
                    if((re.xubu.wei==1)&&(re.xubu.shu[0]==1));
                    else for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);
                }
                printf("i");
            }
        }
    }
}

bigint singlecheng(bigint a,int x)
{
    bigint re;
    memset(re.shu,0,sizeof(int)*1100);
    int i,jin=0,mid;
    for(i=0;(i<a.wei)||jin!=0;i++)
    {
        mid=a.shu[i]*x+jin;
        re.shu[i]=mid%10;
        jin=mid/10;
    }
    re.wei=i;
    return re;
}

bigint moveadd0(bigint a,int k)
{
    int i,j;
    bigint re;
    memset(re.shu,0,sizeof(int)*1100);
    for(i=a.wei-1+k,j=a.wei-1;i>=0;i--,j--)
    {
        if(j<0) re.shu[i]=0;
        else re.shu[i]=a.shu[j];
    }
    re.wei=a.wei+k;
    return re;
}

bigint zhengjia(bigint re,bigint mid)
{
    int i,du,jin=0;
    for(i=0;(i<re.wei)||(i<mid.wei)||(jin!=0);i++)
    {
        du=re.shu[i]+mid.shu[i]+jin;
        re.shu[i]=du%10;
        jin=du/10;
    }
    re.wei=i;
    re.sign=1;
    return re;
}

bigint cheng(bigint a,bigint b)
{
    int i,j,co=0;
    bigint re,mid;
    memset(re.shu,0,sizeof(int)*1100);
    int x[1100];
    memset(x,0,sizeof(int)*1100);
    for(i=0;i<b.wei;i++)
    {
        x[i]=b.shu[i];
    }
    for(i=0;i<b.wei;i++)
    {
        mid=singlecheng(a,x[i]);
        mid=moveadd0(mid,i);
        re=zhengjia(re,mid);
    }
    re.sign=a.sign*b.sign;

    return re;
}


int jud (bigint a,bigint b)
{
    int i;
    if(a.wei>b.wei) return 1;
    else if(a.wei<b.wei) return 0;
    else
    {
        for(i=a.wei-1;i>=0;i--)
        {
            if(a.shu[i]>b.shu[i]) return 1;
            else if (a.shu[i]<b.shu[i]) return 0;
        }
        return 1;
    }
}

bigint jianpu(bigint a,bigint b)
{
    bigint re;
    int j,i;
    re.sign=1;
    memset(re.shu,0,sizeof(int)*1100);
    for(i=0;(i<a.wei)||(i<b.wei);i++)
    {
        if(a.shu[i]>=b.shu[i]) {re.shu[i]=a.shu[i]-b.shu[i];/*if((re.shu[i]==0)&&(i==(a.wei-1))&&(a.wei>1)) a.wei--;*/}
        else
        {
            re.shu[i]=a.shu[i]+10-b.shu[i];
            for(j=i+1;j<a.wei;j++)
            {
                if(a.shu[j]==0) a.shu[j]=9;
                else
                    {
                        a.shu[j]--;
                        //if((a.shu[j]==0)&&(j==(a.wei-1))&&(a.wei>1)) a.wei--;
                        break;
                    }
            }
        }

    }
    re.sign=1;
    re.wei=a.wei;
    while(re.shu[re.wei-1]==0) re.wei--;
    if(re.wei<=0) re.wei=1;
    return re;
}



bigint jia (bigint a,bigint b)
{
    bigint re;
    memset(re.shu,0,sizeof(int)*1100);
    re.sign=1;
    if(a.sign==b.sign)
    {
        if(a.sign==1) re=zhengjia(a,b);
        else {re=zhengjia(a,b);re.sign=-1;}
        return re;
    }
    else
    {
        if(jud(a,b))
        {
            re=jianpu(a,b);
            re.sign=a.sign;
        }
        else
        {
            re=jianpu(b,a);
            re.sign=b.sign;
        }
        return re;
    }
}


bigint jian(bigint a,bigint b)
{
    bigint re;
    memset(re.shu,0,sizeof(int)*1100);
    b.sign*=-1;
    re=jia(a,b);
    /*int i;
    printf("\nin function jian:re=");
    for(i=0;i<re.wei;i++) printf("%d",re.shu[i]);*/

   return re;

}

fushu fang(fushu x,fushu y)
{
    fushu re;
    memset(re.shibu.shu,0,sizeof(int)*1100);
    memset(re.xubu.shu,0,sizeof(int)*1100);
    //int i;
    re.shibu=jian( cheng(x.shibu,y.shibu),cheng(x.xubu,y.xubu) );
    re.xubu=jia( cheng(x.shibu,y.xubu),cheng(x.xubu,y.shibu));
    /*printf("\nin function fang:re.shibu=");
    for(i=0;i<re.shibu.wei;i++) printf("%d",re.shibu.shu[i]);

    printf("\nin function fang:re.xubu=");
    for(i=0;i<re.xubu.wei;i++) printf("%d",re.xubu.shu[i]);*/

    return re;
}

int main()
{
    int n,i;
    char s[50];
    fushu c,re;
    scanf("%s%d",s,&n);
    c=zhuanhuan(s);

    c.shibu=reverse(c.shibu);
    c.xubu=reverse(c.xubu);
    re=c;
    for(i=0;i<n-1;i++)
    {
        re=fang(re,c);
        /*printf("\n第%d次后：\nre=",i);
        shuchu(re);
        printf("\n");*/
    }
    /*printf("以下是结果：\n");
    printf("shibu:\n");
    printf("sign=%d\n",c.shibu.sign);
    printf("实部wei=%d\n",c.shibu.wei);
    for(i=0;i<c.shibu.wei;i++) printf("%d",c.shibu.shu[i]);
    printf("\nxubu:\n");
    printf("sign=%d\n",c.xubu.sign);
    printf("虚部wei=%d\n",c.xubu.wei);
    for(i=0;i<c.xubu.wei;i++) printf("%d",c.xubu.shu[i]);
    printf("\n以下是规范格式:\n");*/
    while(re.shibu.shu[re.shibu.wei-1]==0) re.shibu.wei--;
    if(re.shibu.wei<=0) re.shibu.wei=1;
    while(re.xubu.shu[re.xubu.wei-1]==0) re.xubu.wei--;
    if(re.xubu.wei<=0) re.xubu.wei=1;

    re.shibu=reverse(re.shibu);
    re.xubu=reverse(re.xubu);
    if(n==0) printf("1");
    else shuchu(re);

}
