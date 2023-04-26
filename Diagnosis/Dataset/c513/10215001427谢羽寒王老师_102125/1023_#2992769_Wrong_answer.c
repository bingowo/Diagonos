#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a, const void* b) {
    int s1,s2;
    char* str1, *str2;
    str1 = (char*)a;
    str2 = (char*)b;
    s1 = number(str1);  			//提取第一个字符串中的数字
    s2 = number(str2); 			//提取第二个字符串中的数字
    if(s1 == s2)  return strcmp(str1, str2);
    else {
        if(s1 > s2) return 1;
        else  return -1;
    }
}

int main()
{
    char str[110][40];
    int count = 0;
    int g,j;
    while (scanf("%c ", str[count]) != EOF)
    count++;
      // 输入字符串

    qsort(str, count,sizeof(str[0]),cmp);   // 排序
    g=count-1;
    for (j = 0; j <g; j++){     //输出
       printf("%s ", str[j]);}

    return 0;

}

int number(char* str) {
    int len, i, sum = 0, flag = 0;
    len = strlen(str);
    for (i = 0; i < len; i++)
        if (str[i] >= '0' && str[i] <= '9') {	//提取字符串中的数字
            sum = 10*sum + str[i] - 48;         /*  ①A的ASCII代码为065
                                                     ②a的ASCII代码为097
                                                     ③0（数字零）的ASCII代码为048  */
            flag = 1;
        }
        if (flag == 0) sum = -1;		//没有数字则返回 -1
    return sum;
}





