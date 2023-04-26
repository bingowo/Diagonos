#include<stdio.h>

int main()
{
    char c;
    int flag,len=1,tlen=1;
    scanf("%c",&c);
    if(c=='|')flag=1;
    else flag=0;
    while(scanf("%c",&c))
    {
        if(c=='\n'){if(len<tlen)len=tlen;break;}
        if((flag==1&&c=='-')||(flag==0&&c=='|')){tlen++;flag=abs(flag-1);}
        else {
            if(c=='|')flag=1;
            else flag=0;
            if(len<tlen)len=tlen;
            tlen=1;
        }
    }
    printf("%d",len);
}