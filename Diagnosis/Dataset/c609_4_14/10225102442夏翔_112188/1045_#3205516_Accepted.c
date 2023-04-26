#include<stdio.h>
#include<stdlib.h>
int main(){
    char c, temp;
    int ret1=-1, ret2=-1, ret3=-1, ret4=-1;//是否处于单引号、行注释、块注释、双引号中
    while(scanf("%c", &c)!=EOF){
        if(ret1==-1 && ret4==-1 && c=='/' && ret2==-1 && ret3==-1){//检测注释开始
            scanf("%c", &temp);
            if(temp=='/'){
                ret2 = -1*ret2;
                continue;
            }else if(temp=='*'){
                ret3 = -1*ret3;
                continue;
            }
            else printf("%c", c);
            c = temp;
        }
        if(ret1==-1 && ret4==-1 && c=='*'&& ret3==1){//检测块注释结束
            scanf("%c", &temp);
            while(temp=='*'||temp=='/'){
                if(temp=='/'){
                    ret3 = -1*ret3;
                    break;
                }
                scanf("%c", &temp);
            }
            continue;
        }
        if(c=='\'' && ret4==-1) ret1 = -1*ret1;  //单引号开始（结束）
        if(c=='\"' && ret1==-1) ret4 = -1*ret4;  //双引号开始（结束）
        if(ret2==1 && c=='\n'){  //行注释结束
            ret2 = -1*ret2;
        }
        if(c=='\\'&&(ret1==1||ret4==1)){
            scanf("%c", &temp);
            printf("%c%c",c,temp);
            continue;
        }
        if(ret2!=1 &&ret3!=1) printf("%c", c);  //正常输出
    }
    return 0;
}
