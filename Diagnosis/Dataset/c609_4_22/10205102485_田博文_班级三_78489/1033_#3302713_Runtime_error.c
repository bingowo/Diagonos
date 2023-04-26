#include<stdlib.h>
#include<stdio.h>
#include<string.h>



int main(){
    char base64_chart[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    char src[1024]={0};
    char res[1024]={0};
    gets(src);
    int len=strlen(src);
    int pos,index,bits,ret;
    while(index<len)
    {
        int ch=src[index];
        int cur=(ret<<(6-bits))+(ch>>(2+bits));
        res[pos++]=base64_chart[cur];
        index++;
        bits+=2;
        ret=ch%(1<<bits);
        if(bits==6)
        {
            res[pos++]=base64_chart[ret];
            bits=0;
            ret=0;
        }
    }
    if(bits==2)
    {
        res[pos++]=base64_chart[ret<<4];
        res[pos++]='=';
        res[pos++]='=';
    }
    else if(bits==4)
    {
        res[pos++]=base64_chart[ret<<2];
        res[pos++]='=';
    }
    res[pos]='\0';
    printf("%s\n",res);
    return 0;
}
/*
int main(){
    int n;
    scanf("%d",&n);

    for( int i=0;i<n;i++)
    {
        com();
        printf("case #%d:\n%s\n",&n,res);
    }
    return 0;
}
*/