#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int convert(char s[10001])
{
    char *p = s;
    char *p0 = s;//p0指向第一个元素
    while(*p) p++;
    p = p-1;//p指向最后一个元素
    char s1[10001];
    int i =0;
    while(p != p0){
        s1[i++] = *p;
        p--;
    }
    if(strcmp(s1,s) == 0) return 1;
    else return -1;
}


int convert_num(char s[10001])
{
    char *p = s;
    char *p0 = s;//p0指向第一个元素
    while(*p) p++;
    p = p-1;//p指向最后一个元素
    char s1[10001];
    //int len = strlen(s);
    int i =0;
    while(p != p0){
        s1[i++] = *p;
        p--;
    }
    int conv = atoi(s1);
    return conv;
}


int main()
{
    int n;
    scanf("%d",&n);
    char s[10001];
    itoa(n,s,10);
    //s储存着用字符串表示的整数
    //printf("%s",s);
    int flag = convert(s);
    //检查是否是回文数字
    //如果不是的话
    int cnt = 0;
    int sum = 0;
    while(flag != 1){
            //m是倒转的数字
        int m = convert_num(s);
        sum = m + n;
        char sp[10001];
        itoa(sum,sp,10);
        flag = convert(sp);
        cnt++;
    }
    printf("%d %d",cnt,sum);


}