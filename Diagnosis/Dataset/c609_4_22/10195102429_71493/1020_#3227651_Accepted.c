#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int number(char*str){
    int len,i,sum=0,flag=0;
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]>='0'&& str[i]<='9'){ 
            sum=sum*10+str[i]-48;
            flag=1;
        }
    }
        if(flag==0) sum = -1;
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
    char str[110][40],ch;
    int count = 0;
    int j;
    while(1)//输入以空格分开
	{
	scanf("%s",str[count]);
	count++;
	ch=getchar();
	if(ch=='\n')break;

	}

    qsort(str, count, sizeof(str[0]), strnumcmp);
    for(j=0;j<count;j++){
            if(j!=count-1) printf("%s ", str[j]);
            if(j==count-1) printf("%s\n",str[j]);

     }
    return 0;
}