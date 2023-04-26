#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int nums(char*s)
{
    int sum=0,flag=0,len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            sum=sum*10+s[i]-48;
            flag=1;
        }
    }
    if(flag==0) sum=-1;
    return sum;
}

int strnumcmp(const void*a,const void*b)
{
    int num1,num2;
    char*s1;
    char*s2;
    s1=*(char(*)[31])a;
    s2=*(char(*)[31])b;
    num1=nums(s1);
    num2=nums(s2);
    if(num1==num2)
    {
        return strcmp(s1,s2);
    }
    else return num1-num2;
}

int main()
{
    char s[101][31];
    int len=0;
    while(scanf("%s",s[len])!=EOF)
    {
        len++;
    }
    qsort(s,len,sizeof(s[0]),strnumcmp);
    int i=0;
    for(;i<len-1;i++)
    {
        printf("%s ",s[i]);
    }
    printf("%s\n",s[i]);
    return 0;
}
