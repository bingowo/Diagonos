#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnt;
    int v[478];
}BIGINT;

BIGINT mul(BIGINT x,int b)
{
    BIGINT r;
    r.cnt=0;
    int carry=0;
    for(;r.cnt<x.cnt;r.cnt++)
    {
        int tmp=x.v[r.cnt]*b+carry;
        r.v[r.cnt]=tmp%10;
        carry=tmp/10;
    }
    if(carry) r.v[r.cnt]=carry,r.cnt++;
    if(r.v[r.cnt-1]==0) r.cnt--;
    return r;
}


int main()
{
    char s[1001]={0};
    scanf("%s",s);
    if(strlen(s)==1) printf("1");
    else
    {
        BIGINT re={1,{1}};
        for(int i=0;i<strlen(s);i++)
        {
            if(i==0)
            {
                if(s[i]!=s[i+1])
                    re=mul(re,2);
            }
            else if(i==strlen(s)-1)
            {
                if(s[i]!=s[i-1])
                    re=mul(re,2);
            }
            else
            {
                if(s[i]==s[i-1]&&s[i]==s[i+1]);
                else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
                    re=mul(re,3);
                else
                    re=mul(re,2);
            }
        }
        for(int i=re.cnt-1;i>=0;i--)
            printf("%d",re.v[i]);
    }
    return 0;
}