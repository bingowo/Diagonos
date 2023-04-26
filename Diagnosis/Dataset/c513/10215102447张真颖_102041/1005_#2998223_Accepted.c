#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char s[],char t[])
{
    for(int i=strlen(s)-1;s[i]!='.';i--)
    {
        t[0]=s[i];
        int carry=0,tt=0;
        for(int i=0;i<strlen(t);i++,tt++)
        {
            int tmp=carry*10+t[i]-'0';
            if(tmp<8)
            {
                t[tt]='0';
                carry=tmp;
            }
            else
            {
                t[tt]=tmp/8+'0';
                carry=tmp%8;
            }
        }
        while(carry)
        {
            int tmp=carry*10;
            t[tt++]=tmp/8+'0';
            carry=tmp%8;
        }
    }
    int l=strlen(t)-1;
    while(t[l]==0) t[l]=0,l--;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[53]={0},t[153]={0};
        scanf("%s",s);
        convert(s,t);
        printf("case #%d:\n",cas);
        for(int i=0;i<strlen(t);i++)
        {
            if(i==1) printf("%c%c",'.',t[i]);
            else printf("%c",t[i]);
        }
        printf("\n");
    }
}