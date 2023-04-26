#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void add(char s[],int num)
{
    int len= strlen(s);
    memmove(s+1,s,len+1);
    s[0]=num+'0';
}

void devide(char s[],char out[])
{
    int len= strlen(s);
    int temp,remainder=s[0]-'0';
    int qout=0,index=0;
    for (int i = 0; i < len||remainder!=0; i++) {
        if (i >= len - 1) {
            temp = remainder * 10;
        } else {
            temp = remainder * 10 + s[i + 1] - '0';
        }
        qout = temp / 8;
        remainder = temp % 8;
        out[index++] = qout + '0';
    }
}

void to(char oct[],char dec[])
{
    int len= strlen(oct),tlen=0;
    int temp[180]={0};
    for (int i = len-1; i >=0 ; i--) {
        add(dec,oct[i]-'0');
        devide(dec,temp);
        tlen= strlen(temp);
        memmove(dec,temp,tlen+1);
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        char s[60],oct[60],dec[180]={0};
        scanf("%s",s);
        int len= strlen(s);
        memmove(oct,s+2,len-1);
        to(oct,dec);
        printf("case #%d:\n",i);
        printf("0.%s\n",dec);
    }
    return 0;
}