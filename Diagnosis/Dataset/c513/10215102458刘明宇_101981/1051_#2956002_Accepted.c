#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cntt = 0;
    while(T-- > 0){
    char s[101];
    char x[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
    'O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e',
    'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
    'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
    scanf("%s",s);
    char *p = s;
    int i0 = 7;
    int t[1100] = {0};//全部初始化为0
    while(*p){
        int m = *p;
        //m为对应字符得ascii码
        //转化成8位二进制
        for(int i = i0;i>i0-8 && m>0;i--){
            t[i] = m%2;
            m = m/2;
        }
        i0+=8;
        p++;
    }
    int len = 8*strlen(s);
    //printf("%d\n",len);
    if(len%6 != 0){
        int aim = len + 6 - len%6;
        while(len < aim){
            t[len] = 0;
            len++;
        }
    }
    //再六个一组 将二进制位转化为十进制数
    //创立一个表格储存二进制对应的十进制数
    double dec[201]={0};
    int a0 = 5;
    int cnt = 0;
    int len1 = 0;
    while(a0 < len){
        for(int b = a0;b>a0-6;b--){
            //printf("%d\n",t[b]);
            //printf("%f\n",pow(2.0,(double)a0-b));
            dec[cnt]+= (double)t[b]*pow(2.0,(double)a0-b);
        }
        cnt++;
        a0+=6;
        len1++;//十进制数的个数
    }
   // for(int k = 0;k<len1;k++){
    //    printf("%0.f ",dec[k]);
    //}
    //printf("\n");
    //for(int k = 0;k<len;k++){
    //    printf("%d ",t[k]);
    //}
    //printf("\n");
    int len3 = len/6;
    if(len1%4 != 0){
        printf("case #%d:\n",cntt);
        for(int k = 0;k < len3;k++){
            int m = dec[k];
            printf("%c",x[m]);
        }
        int aim = len1 + 4 - len1 % 4;
        while(len1 < aim){
            printf("%c",'=');
            len1++;
        }
    }
    else{
    printf("case #%d:\n",cntt);
    for(int k = 0;k < len3;k++){
        int m = dec[k];
        printf("%c",x[m]);
    }
    }
    printf("\n");
    cntt++;
    }
}