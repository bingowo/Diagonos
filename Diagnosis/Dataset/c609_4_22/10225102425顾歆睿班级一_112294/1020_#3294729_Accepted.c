#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//提取数字
int num(char *s)
{
    int sum=0,flag=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            sum=10*sum+s[i]-48;
            flag=1;
        }
    }
    if(flag==0)sum=-1;
    return sum;
}

int strnumcmp(const void *a, const void *b)
{
    int num1,num2;
    char *str1, *str2;
    str1=*(char(*)[31])a;
    str2=*(char(*)[31])b;
    num1=num(str1);
    num2=num(str2);
    if(num1==num2)
        return strcmp(str1,str2);
    else
        return num1-num2;
}

int main()
{
     char s[110][31];
     int cnt=0;
     while(scanf("%s",s[cnt])!=EOF)
        cnt++;//输入一堆字符串
    qsort(s,cnt,sizeof(s[0]),strnumcmp);//但是sizeof(char)不对欸
    for(int i=0;i<cnt;i++)
        printf("%s%c",s[i],i==cnt-1?'\n':' ');
    return 0;
}