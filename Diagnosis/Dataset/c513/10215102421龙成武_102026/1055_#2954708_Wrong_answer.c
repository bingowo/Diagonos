#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,x,y,d,pos,hash[256];
    char s[1000001];
    //scanf("%s", s);
    gets(s);
    memset(hash, -1, sizeof(hash));      //hash表记录某个字符最后一次出现的下标
    x = 0;pos = 0;                        //x就是最长子串的长度，对应pos
    y = 0;                           //y即f(i-1),不是第i-1个元素及其之前的字符串的最长无重复子串，而是以第i-1个元素结尾的最长无重复子串长度
    for (i = 0;i < strlen(s);i++)
    {
        printf("%c",s[i]);
    }
    putchar('\n');
    return 0;
}