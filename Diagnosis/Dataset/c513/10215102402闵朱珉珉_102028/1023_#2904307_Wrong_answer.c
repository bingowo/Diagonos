#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[110][31];
    int num=0;
    while (scanf("%s",str[num])!=EOF)
        num++;
    int number(char *s)
    {
        int sum=0,flag=0,len=strlen(s);
        for (int i=0;i<len;i++)
        {
            if (s[i]>='0'&&s[i]<='9') sum=sum*10+s[i]-'0';
            flag=1;
        }
        if (flag==0) sum=-1;
        return sum;
    }
    int strnumcmp(const void *a,const void *b)
{
    char *a1,*b1;
    a1=*(char (*)[31])a;b1=*(char (*)[31])b;
    int numbera=number(a1),numberb=number(b1);
    if (numbera==numberb) return strcmp(a1,b1);
    else return numbera-numberb;
}
    qsort(str,num,sizeof(str[0]),strnumcmp);
    for (int i=0;i<num;i++)
        printf("%s%c",str[i],i==num-1?'\n':' ');
    return 0;
}
