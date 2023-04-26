#include<stdio.h>
#include<string.h>
int main() {
    char c[1024];
    int FLAG=0;//指示是否遇到/*
    int quote=-1;//指示是否在引号之中,1在，-1不在
    int HasPrint=0;//指示当前行是否有输出。

    while(gets(c)) {
        HasPrint=0;
        for(int i=0; i<strlen(c); i++) {
            if(FLAG) {
                if(c[i]=='*'&&c[i+1]=='/') {
                    FLAG=0;
                    i++;//跳过  /* 两个字符的输出
                    continue;
                }
            } else {
                if(c[i]=='"')quote*=-1;
                if(quote==-1) { //  如果不在引号之中
                    if(c[i]=='/'&&c[i+1]=='/'){ //  遇到//直接跳过本行  c[i+1]不会越界，最多访问到'\0'
                        if(i==0) HasPrint = 1;
                        break;
                    }
                    if(c[i]=='/'&&c[i+1]=='*') {
                        FLAG=1;
                    }
                }
                if(!FLAG) {
                    putchar(c[i]);
                    HasPrint=1;
                }
            }

        }
        if(HasPrint)printf("\n");
    }
    return 0;
}