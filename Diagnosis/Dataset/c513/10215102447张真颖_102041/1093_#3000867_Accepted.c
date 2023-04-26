#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct
{
    int cnt;
    int v[MAX];
}BIGINT;

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

int main()
{
    char s[102]={0};
    scanf("%s",s);
    BIGINT bi={strlen(s),{0}};
    int i=0,j=bi.cnt-1;
    for(;i<strlen(s);i++,j--)
    {
        if(s[i]=='9') break;
        else bi.v[j]=s[i]-'0';
    }
    while(i<strlen(s))
    {
        bi.v[j--]=8;
        i++;
    }
    do
    {
        add2(&bi);
    }while(Div(bi)==0);
    for(int i=bi.cnt-1;i>=0;i--)
        printf("%d",bi.v[i]);
    return 0;
}