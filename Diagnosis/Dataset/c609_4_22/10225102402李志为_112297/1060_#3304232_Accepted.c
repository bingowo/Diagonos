#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*R(char*s)
{
    if(*s){
        char t[201];
        *t=*(t+1)=*s;//递归思想 对于s最左边的字符串复制，将其存到t里，并将其与s比较，然后将较大的那个作为s，返回
        if(strcmp((strcpy(t+2,R(s+1))-2),s)<0) strcpy(s,t);//strcpy返回的是t+2的地址（第一个参数）所以要-2，来表示t
    }
    return s;
}
int main()
{
    char s[201];
    scanf("%s",s);
    printf("%s",R(s));
	return 0;
}