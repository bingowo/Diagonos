// string 读入串 长度 10100
//while < 串长度 判断不是数字为字符串
//              碰到字母保存下  < 10010
//              数字则放入三位数字判断中
//                      数字：继续统计
//                      非数字：得到数字
//              讲前面得到的串按照次数print
//重复上述循环

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char initial[10100];
char temp[10100];
int number = 0;

int main(){
    scanf("%s",initial);
    int length = strlen(initial);
    int idx = 0;
    int idxt = 0;
    while(idx <=length){
        if(initial[idx]<='z' && initial[idx]>='A'&& number == 0){
            temp[idxt] = initial[idx];
            idx++;
            idxt++;
        }else if(initial[idx]<='9' && initial[idx]>='0'){
            number = number*10+initial[idx]-'0';
            idx++;
        }else if(((initial[idx]<='z' && initial[idx]>='A')||(initial[idx] = '0'))&& number != 0){
                for(int i = 0; i < number;i++){
                    printf("%s",temp);
                }
                for(int j = 0; j < idxt;j++){
                    temp[j] = NULL;
                }
                idxt = 0;
                number = 0;

        }else if(idx == length){
            for(int i = 0; i < length;i++){
                printf("%c",initial[i]);
            }

        }
    }
}