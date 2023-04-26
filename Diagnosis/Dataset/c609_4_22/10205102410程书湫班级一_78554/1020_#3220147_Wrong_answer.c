#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int number(char *s)
{
    int sum=0,flag=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum=10*sum+s[i]-48;
            flag=1;
        }
        if(flag==0) sum=-1;
        return sum;
    }
}
int strnumcmp(const void *a,const void *b)
{
    int number1,number2;
    char *str1,*str2;
    str1=(char *)a;
    str2=(char *)b;
    number1=number(str1);
    number2=number(str2);
    if(number1==number2) return strcmp(str1,str2);
    else
        return number1-number2;
}
int main()
{
    char s[100][31];
    int n=0;
    while(scanf("%s",s[n])!=EOF){n++;}
    qsort(s,n,sizeof(s[0]),strnumcmp);
    for(int i=0;i<n;i++)
    printf("%s%c",s[i],i==n-1?'\n':' ');
    return 0;
}
