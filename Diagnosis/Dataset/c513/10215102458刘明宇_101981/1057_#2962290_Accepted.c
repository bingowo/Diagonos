#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s[1001];
    scanf("%s",s);
    char res[2000];
    char *pl = s;
    while(*pl){
        pl++;
    }
    pl--;//pl指向最后一个元素
    char *p = s;
    int front = 1000;//来记录最大，即最前面的位置
    int last = 1000;
    res[front] = *p;
    p++;
    while(*p){
        if(*p >= res[front]){
            front--;
            res[front] = *p;
        }
        else{
            last++;
            res[last] = *p;
        }
        p++;
    }
    for(int i = front;i<=last;i++){
        if(res[i]>='a' && res[i] <='z') res[i] = res[i]-32;
        printf("%c",res[i]);
    }
    //int x = 7;
    //if(*p > *p1){
     //   x = 1;
    //}
    //printf("%d",x);
}
