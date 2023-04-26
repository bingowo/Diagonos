#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct
{
    int cnt;
    int v[MAX];
}BIGINT;

void add1(BIGINT* bi)
{
    int carry=1;
    for(int i=0;i<bi->cnt;i++)
    {
        int t=carry+bi->v[i];
        bi->v[i]=t%10;
        carry=t/10;
    }
    if(carry)
        bi->v[bi->cnt]=carry,bi->cnt+=1;
}
void add2(BIGINT* bi)
{
    int carry=1;
    for(int i=0;i<bi->cnt;i++)
    {
        int t=carry+bi->v[i];
        bi->v[i]=t%9;
        carry=t/9;
    }
    if(carry)
        bi->v[bi->cnt]=carry,bi->cnt+=1;
}
int Div(BIGINT bi)
{
    int cheat=0;
    if(bi.v[bi.cnt-1]<9)
    {
        bi.cnt--;
        cheat=bi.v[bi.cnt];
    }
    for(int i=bi.cnt-1;i>=0;i--)
    {
        int t=10*cheat+bi.v[i];
        bi.v[i]=t/9;
        cheat=t%9;
    }
    return cheat;
}
int judge(BIGINT bi)
{
    if(Div(bi))
    {
        for(int i=0;i<bi.cnt;i++)
            if(bi.v[i]==9) return 1;
        return 0;
    }
    else return 1;
}

int main()
{
    char s[102]={0};
    scanf("%s",s);
    BIGINT bi;
    bi.cnt=0;
    for(int i=strlen(s)-1;i>=0;i--,bi.cnt++)
        bi.v[bi.cnt]=s[i]-'0';
    if(judge(bi))
    {
        do
        {
            add2(&bi);
        }while(Div(bi));
    }
    else
    {
        do
       {
           add1(&bi);
        }while(judge(bi));
    }
    for(int i=bi.cnt-1;i>=0;i--)
        printf("%d",bi.v[i]);
    return 0;
}