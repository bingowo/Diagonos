#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



int cmp(const void *a,const void *b)
{
    char *s1,*s2;
    char ch1,ch2;
    s1=(char *)a;
    s2=(char *)b;
    while (*s1&&*s2){
        ch1=(*s1)>='a'?*s1-32:*s1;
        ch1=(*s2)>='a'?*s2-32:*s2;
        if ()
    }
}

int main()
{
    int p[26];
    char s[27];
    while (scanf("%s\n",s)!=EOF)

    char str[2200];
    char a[100][21];
    gets(str);
    int count=0,i=0;
    while (1){
        int j=0;
        while (str[i]!=' '&&str[i]) a[count][j++]=str[i++];
        a[count][j]='\0';
        count++;
        if (!str[i]) break;
        else i++;
    }
    return 0;
}