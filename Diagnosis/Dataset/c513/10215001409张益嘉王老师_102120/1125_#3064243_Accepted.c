#include <stdio.h>
#include <stdlib.h>

long long maxyue(long long a,long long b)
{
    if((a==0)||(b==0)) return 0;
    else if(a==b) return a;
    else if(a>b)
    {
        if(a%b==0) return b;
        else return maxyue(b,a%b);
    }
    else return maxyue(b,a);
}

long long qiuqian(char s[])
{
    int len=strlen(s),i;
    long long zi=0;

    for(i=0;i<len;i++)
    {
        if(s[i]=='[')break;
        if(s[i]=='.')continue;
        zi*=10;
        zi+=s[i]-'0';
    }

    //printf("in qiuqian zi=%lld\n",zi);
    return zi;
}

long long qiubxmu(int co)
{
    int i;
    long long re=1;
    for(i=0;i<co;i++)
    {
        re*=10;
    }
    //printf("in qiubxmu re=%lld\nco=%d\n",re,co);
    return re;
}

long long qiuxhmu(int co,int bxco)
{
     int i;
    long long re=0;
    for(i=0;i<co;i++)
    {
        re*=10;
        re+=9;
    }
    for(i=0;i<bxco;i++)
    {
        re*=10;
    }
    //printf("in qiuxhmu re=%lld\nco=%d\n",re,co);
    return re;
}

int main()
{
    /*long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",maxyue(a,b));*/
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[20];
        long long bxmu=1,xhmu=1,bxzi=0,xhzi=0,mid=1,mid2=1;
        memset(s,0,sizeof(char)*20);
        scanf("%s",s);
        int j,k=0,len=strlen(s),bxco=0;

        for(j=0;j<len;j++)
        {
            //printf("hello1\n");
            if(s[j]=='.')
            {
                //printf("j=%d\n",j);
                for(j++;j<len;j++)
                {
                    if(s[j]=='[') break;
                    bxco++;
                    //printf("test:bxco=%d\n",bxco);
                }
                break;
            }
        }

        for(j=0;j<len;j++)
        {
            //printf("hello2\n");
            if(s[j]=='[')
            {
                for(j++,k=0;j<len;j++,k++)
                {

                    if(s[j]==']') break;
                    xhzi*=10;
                    xhzi+=s[j]-'0';
                }
                //printf("test:in main xhzi=%lld\n",xhzi);
                break;

            }

        }

        bxmu=qiubxmu(bxco);
        bxzi=qiuqian(s);
        mid=maxyue(bxzi,bxmu);
        if(mid!=0)
        {
            bxzi/=mid;
            bxmu/=mid;
        }
        else
        {
            bxzi=0;
            bxmu=1;
        }

        xhmu=qiuxhmu(k,bxco);
        mid2=maxyue(xhzi,xhmu);
        if(mid2!=0)
        {
             xhzi/=mid2;
             xhmu/=mid2;
        }
        else
        {
            xhzi=0;
            xhmu=1;
        }

        long long du=maxyue(xhmu,bxmu),remu,rezi;
        remu=(xhmu/du)*bxmu;
        rezi=(xhzi*(remu/xhmu))+(bxzi*(remu/bxmu));

        du=maxyue(remu,rezi);
        if(du!=0)
        {
             rezi/=du;
             remu/=du;
        }
        else
        {
            rezi=0;
            remu=1;
        }

        printf("case #%d:\n",i);
        if(rezi==0) printf("0\n");
        else if(remu==1) printf("%lld\n",rezi);
        else
        {
            printf("%lld/%lld\n",rezi,remu);
        }

    }
}
