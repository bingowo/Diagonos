//1049 高精度-高精度
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s1[510], s2[510];
void minus(){
    if(strlen(s2)>strlen(s1) || (strlen(s1)==strlen(s2))&&strcmp(s1, s2)<0){
        char temp[510]; //交换AB
        strcpy(temp, s1);
        strcpy(s1, s2);
        strcpy(s2, temp);
        printf("%c", '-'); //负数
    }
    int len1 = strlen(s1), len2 = strlen(s2), pos = 1, temp = 0;
    while(pos<=len2){  //高精度相减（字符串）
        s1[len1-pos] -= s2[len2-pos]-48+temp;
        if(s1[len1-pos]<'0'){
            s1[len1-pos] += 10;
            temp = 1;
        }else temp = 0;
        pos++;
    }
    while(temp!=0){
        s1[len1-pos] -= temp;
        if(s1[len1-pos]<'0'){
            s1[len1-pos] += 10;
            temp = 1;
        }else temp = 0;
        pos++;
    }
}
int main(){
    int len, flag;
    while(scanf("%s", s1)!=EOF){
        scanf("%s", s2);
        if(strcmp(s1, s2)==0){ //相同输出0
            printf("%d\n", 0);
            continue;
        }
        minus();
        len = strlen(s1);
        flag = 0;
        for(int i=0; i<len; i++){
            if(flag==0 && s1[i]=='0') continue;
            printf("%c", s1[i]);
            flag = 1; //无前导0了
        }
        printf("\n");
    }
    return 0;
}