#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void readit(char *p,int *pow) {
    while(*p) {
        int sign = 1;
        int xishu=0;
        if(*p=='-') sign=-1,p++;
        else if(*p=='+') p++;
        while(isdigit(*p)) {
            xishu = xishu * 10 + *p - '0';//先乘十，再加个位数
            p++;
        }
        if(xishu==0) xishu=1;//无数字有项，则系数是1

        if(!*p) pow[0]=xishu*sign;
        else if(*p=='x') {
            if(*(p+1)=='^') pow[*(p+2)-'0']=xishu*sign,p+=3;
            else pow[1]=xishu*sign,p++;
        }
    }
}

int main(){
    char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)==2) {
        //scanf只要遇到空格就停止该字符串的输入
        int powf[51]={0}, powl[51]={0},ans[51]={0};
        readit(s1,powf);
        readit(s2,powl);
        
        for(int i=0;i<51;i++)
        {
            if(powf[i]=='\0') continue;
            printf("%d\n",powf[i]);
        }
    }

    return 0;
}
