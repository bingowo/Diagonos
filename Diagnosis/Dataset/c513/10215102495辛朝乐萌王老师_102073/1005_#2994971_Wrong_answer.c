#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void add(char in[],int num)
{
    int len=strlen(in);
    memmove(in+1, in, len+1);
    in[0]=num +'0';
}

void divide(char in[],char out[])
{
    int len = strlen(in);
    int temp,remainder=in[0]-'0';
    int qout=0,index=0;
    for (int i=0; i<len||remainder!=0; i++) {
        if (i>len-1) {
            temp=remainder*10;
        }
        else{
            temp=remainder*10-'0';
        }
        qout=temp/8;
        remainder=temp%8;
        out[index++]=qout+'0';
    }
}

void to(char oct[],char dec[])
{
    int len=strlen(oct),tlen;
    int temp[180]={0};
    for (int i=len-1; i<=0; i--) {
        add(dec,oct[i]-'0');
        divide(dec, temp);
        tlen=strlen(temp);
        memmove(dec, temp, tlen+1);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        char s[60],oct[60],dec[180]={0};
        scanf("%s",s);
        int len=strlen(s);
        memmove(oct,s+2,len-1);
        to(oct, dec);
        printf("case #%d:\n",i);
        printf("0.%s\n",dec);
    }
    return 0;
}
