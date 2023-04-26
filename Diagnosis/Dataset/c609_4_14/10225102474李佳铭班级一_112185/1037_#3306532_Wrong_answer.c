#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    char s[100001];
    scanf("%s",s);
    //起始位置
    int start = 0;

    //最大长度
    int max = 0;

    //计数器
    int x = 0;

    //映照表
    int a[128];
    for(int i = 0;i < 128;i++) a[i] = -1;
    
    //逐个筛查
    int len = strlen(s);
    for(int i = 0;i < len;i++){
        if(a[s[i]] < 0){
            a[s[i]] = 1;
            x++;
        }
        else{
            if(max < x){
                max = x;
                start = i - x;
                x = 0;
            }
            for(int i = 0;i < 128;i++) a[i] = -1;
            a[s[i]] = 1;
        }
    }

    //max与最后一次的x进行比较
    if(max < x){
        max = x;
        start = len - x;
    }

    //结束位置
    int end = start + max;

    //打印最大不重复字符串
    for(int j = start;j < end; j++){
        printf("%c",s[j]);
    }
}