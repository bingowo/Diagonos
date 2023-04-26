#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char str[110][31];
int count=0;

int numb(char*s)
{
    int sum=0,flag=0,len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum=sum*10+s[i]-48;
            flag=1;
        }
    }
    if(flag==0) sum=-1;
    return sum;
}

int strnumcmp(const void *a,const void *b)
{
    int num1,num2;
    char *str1,*str2;
    str1=*(char(*)[31])a; str2=*(char(*)[31])b;
    num1=numb(str1); num2=numb(str2);
    if(num1==num2)
        return strcmp(str1,str2);
    else
        return num1-num2;
}

int main()
{
    while(scanf("%s",str[count])!=EOF)
        count++;
    qsort(str,count,sizeof(str[0]),strnumcmp);
    for(int i=0;i<count;i++)
        printf("%s%c",str[i],i==count-1?'\n':' ');
    return 0;
}
