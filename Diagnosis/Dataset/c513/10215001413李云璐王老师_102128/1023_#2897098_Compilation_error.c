#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int number(char* str) {
    int len, I, sum = 0, flag = 0;
    len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] >= '0' && str[i] <= '9') {	//提取字符串中的数字
            sum = 10*sum + str[i] – 48;
            flag = 1;
        }
        if (flag == 0) sum = -1;		//没有数字则返回 -1
    return sum;
}


   int strnumcmp(const void* a, const void* b) {
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
    char s[110][40];
    int count=0;
    while(scanf("%s",s[count])!=EOF)
    count++;
    qsort(s,count,sizeof(s[0]),strnumcmp);
    for(int k=0;k<count;k++)
    {
        printf("%s ",s[k]);
    }
    return 0;
    
}