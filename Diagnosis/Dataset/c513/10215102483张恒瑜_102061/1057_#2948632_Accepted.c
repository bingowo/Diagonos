#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[1002];
    scanf("%s", str);
    char r[1002] = "";
    for (int i = 0; i < strlen(str); i++) 
    {
        char s1[1002] = {0}, s2[1002] = {0};
        s1[0] = s2[0] = toupper(str[i]); //转大写
        strcat(s1, r); strcat(r, s2); //拼接
        if (strcmp(s1, r) > 0) strcpy(r, s1); //比较替换
    }
    printf("%s", r);
}