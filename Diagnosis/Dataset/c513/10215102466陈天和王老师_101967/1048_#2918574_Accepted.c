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

        if(*p=='\0'){
            pow[0]=xishu*sign;//常数项无数字，则为0
            return;
        }

        if(xishu==0) xishu=1;//含x的项无数字，则系数是1
        if(*p=='x') {
            if(*(p+1)=='^'){
                char *q;
                int zhishu=0;
                q=p+2;
                while(isdigit(*q)) {
                    zhishu = zhishu * 10 + *q - '0';//先乘十，再加个位数
                    q++;
                }//字符非单个数字转数字
                pow[zhishu]=xishu*sign,p+=3;

            }

            else pow[1]=xishu*sign,p++;
        }
    }
}

int main(){
    char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)==2) {
        //scanf只要遇到空格就停止该字符串的输入
        int powf[51]={0}, powl[51]={0},ans[101]={0};
        readit(s1,powf);
        readit(s2,powl);
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                ans[i+j]+=powf[i]*powl[j];
            }
        }

        for(int i=100;i>=0;i--)
        {
            if(ans[i]=='\0') continue;
            printf("%d ",ans[i]);
        }
        printf("\n");//输出
    }

    return 0;
}
