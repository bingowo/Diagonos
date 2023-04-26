#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnti,cntf;
    int vi[501],vf[501];
}BIGDOUBLE;

BIGDOUBLE tra(char sa[])
{
    BIGDOUBLE biga;
    biga.cnti=0;
    biga.cntf=0;
    for(;biga.cnti<strlen(sa)&&sa[biga.cnti]!='.';biga.cnti++);
    if(biga.cnti<strlen(sa)) biga.cntf=strlen(sa)-biga.cnti-1;
    else biga.cntf=0;
    for(int i=0;i<biga.cnti;i++)
        biga.vi[i]=sa[biga.cnti-i-1]-'0';
    for(int i=0;i<biga.cntf;i++)
        biga.vf[i]=sa[biga.cnti+i+1]-'0';
    if(biga.cnti==0) biga.vi[0]=0,biga.cnti=1;
    if(biga.cntf==0) biga.vf[0]=0,biga.cntf=1;
    return biga;
}
int compere(BIGDOUBLE biga,BIGDOUBLE bigb)
{
    if(biga.cnti<bigb.cnti) return -1;
    else if(biga.cnti>bigb.cnti) return 1;
    else
    {
        for(int i=biga.cnti-1;i>=0;i--)
        {
            if(biga.vi[i]>bigb.vi[i]) return 1;
            else if(biga.vi[i]<bigb.vi[i]) return -1;
        }
        int i=0;
        for(;i<biga.cntf&&i<bigb.cntf;i++)
        {
            if(biga.vf[i]>bigb.vf[i]) return 1;
            else if(biga.vf[i]<bigb.vf[i]) return -1;
        }
        if(i<biga.cntf) return 1;
        else if(i<bigb.cntf) return -1;
        return 0;
    }
}
BIGDOUBLE sub(BIGDOUBLE biga,BIGDOUBLE bigb)
{
    BIGDOUBLE bigr;
    bigr.cnti=0;
    bigr.cntf=biga.cntf>bigb.cntf?biga.cntf:bigb.cntf;
    int cheat=0;
    if(biga.cntf>bigb.cntf)
    {
        for(int i=biga.cntf-1;i>=0;i--)
        {
            int tmp;
            if(i>=bigb.cntf) tmp=biga.vf[i]-cheat;
            else tmp=biga.vf[i]-cheat-bigb.vf[i];
            if(tmp<0) cheat=1;
            else cheat=0;
            bigr.vf[i]=tmp+cheat*10;

        }
    }
    else
    {
        for(int i=bigb.cntf-1;i>=0;i--)
        {
            int tmp;
            if(i>=biga.cntf) tmp=0-cheat-bigb.vf[i];
            else tmp=biga.vf[i]-bigb.vf[i]-cheat;
            if(tmp<0) cheat=1;
            else cheat=0;
            bigr.vf[i]=tmp+cheat*10;
        }
    }
    if(biga.cnti>bigb.cnti)
    {
        int i;
        for(i=0;i<biga.cnti;i++)
        {
            int tmp;
            if(i>=bigb.cnti) tmp=biga.vi[i]-cheat;
            else tmp=biga.vi[i]-cheat-bigb.vi[i];
            if(tmp<0) cheat=1;
            else cheat=0;
            bigr.vi[i]=tmp+cheat*10;
        }
        bigr.cnti=i;
    }
    else
    {
        int i;
        for(i=0;i<bigb.cnti;i++)
        {
            int tmp;
            if(i>=biga.cnti) tmp=0-cheat-bigb.vi[i];
            else tmp=biga.vi[i]-cheat-bigb.vi[i];
            if(tmp<0) cheat=1;
            else cheat=0;
            bigr.vi[i]=tmp+cheat*10;
        }
        bigr.cnti=i;
    }
    for(;bigr.vi[bigr.cnti-1]==0&&bigr.cnti>=0;bigr.cnti--);
    return bigr;
}
BIGDOUBLE f(BIGDOUBLE bigr,int n)
{
    if(n>=bigr.cntf) return bigr;
    else
    {
        if(bigr.vf[n]<5) return bigr;
        else
        {
            int carry=0;
            for(int i=n-1;i>=0;i--)
            {
                int tmp=0;
                if(i==n-1) tmp=bigr.vf[i]+1+carry;
                else tmp=bigr.vf[i]+carry;
                bigr.vf[i]=tmp%10;
                carry=tmp/10;
                if(carry==0) break;
            }
            if(carry==0) return bigr;
            else
            {
                for(int i=0;i<bigr.cnti;i++)
                {
                    int tmp=bigr.vi[i]+carry;
                    bigr.vi[i]=tmp%10;
                    carry=tmp/10;
                    if(carry==0) break;
                }
                if(carry) bigr.vi[bigr.cnti]=carry,bigr.cnti+=1;
                return bigr;
            }
        }
    }
}

int main()
{
    BIGDOUBLE biga,bigb,bigr;
    int N;
    char sa[501],sb[501];
    scanf("%s%s%d",sa,sb,&N);
    biga=tra(sa);
    bigb=tra(sb);
    int sign=compere(biga,bigb);
    if(sign==0) printf("0");
    else if(sign==1) bigr=sub(biga,bigb);
    else bigr=sub(bigb,biga);
    bigr=f(bigr,N);
    if(sign==-1) printf("-");
    if(bigr.cnti==0) printf("0");
    else
    {
        for(int i=bigr.cnti-1;i>=0;i--)
            printf("%d",bigr.vi[i]);
    }
    printf(".");
    for(int i=0;i<N;i++)
        printf("%d",i<bigr.cntf?bigr.vf[i]:0);
    return 0;
}