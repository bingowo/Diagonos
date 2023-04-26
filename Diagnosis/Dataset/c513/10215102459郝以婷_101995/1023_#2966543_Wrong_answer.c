#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strnumcmp(const void* a,const void* b)
{
    char *s1,*s2;
    int ifnumber1=-2,ifnumber2=-2,len1,len2,i,number1=0,number2=0;
    s1=*(char(*)[31])a;
    s2=*(char(*)[31])b;
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=0;i<len1;i++)
    {
        if(*(s1+i)<=56&&*(s1+i)>=48)
            {number1=*(s1+i)-48+number1*10;
            ifnumber1=-1;}
    }
    for(i=0;i<len2;i++)
    {
        if(*(s2+i)<=56&&*(s2+i)>=48)
            {number2=*(s2+i)-48+number2*10;
            ifnumber2=-1;}
    }
    //printf("%d %d",ifnumber1,ifnumber2);
    if(ifnumber1==-2&&ifnumber2==-2)
        return strcmp(s1,s2);
    else if((ifnumber1+ifnumber2)==-3)
        return ifnumber1-ifnumber2;
    else
        return number1-number2;
}

int main()
{
    int i=0,j;
    char str[101][31];
    while(scanf("%s",&str[i++])!=EOF);
    qsort(str,i-1,sizeof(str[0]),strnumcmp);
    for(j=0;j<i-1;j++)
    {
        printf("%s ",str[j]);
    }
    return 0;
}
