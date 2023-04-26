#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strnumcmp(const void* a,const void* b)
{
    char *s1,*s2;
    int ifnumber1=0,ifnumber2=0,len1,len2,i;
    s1=*(char(*)[31])a;
    s2=*(char(*)[31])b;
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=0;i<len1;i++)
    {
        if(*(s1+i)<=56&&*(s1+i)>=48)
            ifnumber1=*(s1+i)+ifnumber1*10;
    }
    for(i=0;i<len2;i++)
    {
        if(*(s2+i)<=56&&*(s2+i)>=48)
            ifnumber2=*(s2+i)+ifnumber2*10;
    }
    if(ifnumber1==ifnumber2)
        return strcmp(s1,s2);
    else
        return ifnumber1-ifnumber2;
}

int main()
{
    int i=0,j;
    char str[101][31];
    while(scanf("%s",&str[i++])!=EOF);
    qsort(str,i-1,sizeof(str[0]),strnumcmp);
    for(j=0;j<i;j++)
    {
        printf("%s ",str[j]);
    }
    return 0;
}
