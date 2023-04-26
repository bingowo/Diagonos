//1060
#include <stdio.h>
#include <string.h>
int main(){
    char s[110];
    scanf("%s", s);
    int pos=0, len1=strlen(s), temp;
    while(pos<len1-1){
        temp=pos+1;
        while(s[temp-1]==s[temp] && temp<len1-1) temp++; //找到第一个不一样的字符
        if(s[temp]>s[pos]){ //若比它小
            while(pos<temp){
                printf("%c%c", s[pos], s[pos]); //输出两次
                pos++;
            }
        }else{
            while(pos<temp){
                printf("%c", s[pos]);
                pos++;
            }
        }
    }
    printf("%c", s[len1-1]);
    return 0;
}