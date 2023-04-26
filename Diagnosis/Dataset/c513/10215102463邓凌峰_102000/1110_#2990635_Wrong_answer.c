#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 100
#define BigNUm 10007

typedef struct{
    char unknow;
    int xishu;
    int changshu;
}My;

int main()
{
    char s[LEN]={0};scanf("%s",s);
    My left={0},right={0};
    int i=0;
    while(s[i]!='='){
        if(isalpha(s[i])){
            left.unknow=s[i];
            left.xishu=1;
            i++;
        }
        if(isdigit(s[i])){
            int tmp=0;
            while(isdigit(s[i])){
                tmp=tmp*10+s[i++]-'0';
            }
            if(s[i]=='-' || s[i]=='+' ||s[i]=='='){
                left.changshu+=tmp;
            }
            else if(isalpha(s[i])){
                left.unknow=s[i];
                left.xishu+=tmp;
                i++;
            }

        }
        if(s[i]=='+'){
            i++;
            if(isalpha(s[i])){
                left.unknow=s[i];
                left.xishu+=1;
                i++;
            }
            if(isdigit(s[i])){
                int tmp=0;
                while(isdigit(s[i])){
                    tmp=tmp*10+s[i++]-'0';
                }
                if(s[i]=='-' || s[i]=='+' ||s[i]=='='){
                    left.changshu+=tmp;
                }
                else if(isalpha(s[i])){
                    left.unknow=s[i];
                    left.xishu+=tmp;
                    i++;
                }
            }
        }
        if(s[i]=='-'){
            i++;
            if(isalpha(s[i])){
                left.unknow=s[i];
                left.xishu+=-1;
                i++;
            }
            if(isdigit(s[i])){
                int tmp=0;
                while(isdigit(s[i])){
                    tmp=tmp*10+s[i++]-'0';
                }
                tmp*=-1;
                if(s[i]=='-' || s[i]=='+' ||s[i]=='='){
                    left.changshu+=tmp;
                }
                else if(isalpha(s[i])){
                    left.unknow=s[i];
                    left.xishu+=tmp;
                    i++;
                }
            }
        }
    }

    i++;

    while(i<strlen(s)){
        if(isalpha(s[i])){
            right.unknow=s[i];
            right.xishu+=1;
            i++;
        }
        if(isdigit(s[i])){
            int tmp=0;
            while(isdigit(s[i])){
                tmp=tmp*10+s[i++]-'0';
            }
            if(s[i]=='-' || s[i]=='+' ||s[i]=='=' || i>=strlen(s)-1){
                right.changshu+=tmp;
            }
            else if(isalpha(s[i])){
                right.unknow=s[i];
                right.xishu+=tmp;
                i++;
            }

        }
        if(s[i]=='+'){
            i++;
            if(isalpha(s[i])){
                right.unknow=s[i];
                right.xishu+=1;
                i++;
            }
            if(isdigit(s[i])){
                int tmp=0;
                while(isdigit(s[i])){
                    tmp=tmp*10+s[i++]-'0';
                }
                if(s[i]=='-' || s[i]=='+' ||s[i]=='='){
                    right.changshu+=tmp;
                }
                else if(isalpha(s[i])){
                    right.unknow=s[i];
                    right.xishu+=tmp;
                    i++;
                }
            }
        }
        if(s[i]=='-'){
            i++;
            if(isalpha(s[i])){
                right.unknow=s[i];
                right.xishu+=-1;
                i++;
            }
            if(isdigit(s[i])){
                int tmp=0;
                while(isdigit(s[i])){
                    tmp=tmp*10+s[i++]-'0';
                }
                tmp*=-1;
                if(s[i]=='-' || s[i]=='+' ||s[i]=='='){
                    right.changshu+=tmp;
                }
                else if(isalpha(s[i])){
                    right.unknow=s[i];
                    right.xishu+=tmp;
                    i++;
                }
            }
        }
    }



    char un;
    if(isalpha(left.unknow)){
        un=left.unknow;
    }
    else un=right.unknow;
    int XS=left.xishu-right.xishu;
    int CS=right.changshu-left.changshu;
    double ans=CS*1.0/XS;
    printf("%c=%.3f",un,ans);



    return 0;
}
