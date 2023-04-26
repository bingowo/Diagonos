#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *s1=(char *)a,*s2=(char *) b;
    int no1=1,no2=1,num1=0,num2=0;
    int len=strlen(s1);
    for(int i=0;i<len;i++)
    {
        if(isdigit(s1[i])) {no1=0;break;}
    }
    len=strlen(s2);
    for(int i=0;i<len;i++)
    {
        if(isdigit(s2[i])) {no2=0;break;}
    }
    if(no1&&no2) return strcmp(s1,s2);
    else if(no1) return -1;
    else if(no2) return 1;
    int i=0;
    for(;;i++) {if(isdigit(s1[i])) break;}
    for(;isdigit(s1[i]);i++) {num1=num1*10+(s1[i]-'0');}
    i=0;
    for(;;i++) {if(isdigit(s2[i])) break;}
    for(;isdigit(s2[i]);i++) {num2=num2*10+(s2[i]-'0');}
    if(num1==num2) return strcmp(s1,s2);
    else if(num1>num2) return 1;
    else return -1;
}
int main()
{
    char s[100][100];
    int i=0;
    do{
        scanf("%s",s[i++]);
    }while(getchar()!='\n');
    qsort(s,i,sizeof(s[0]),cmp);
    for(int j=0;j<i;j++)
    {
        if(j!=i-1) printf("%s ",s[j]);
        else if(j==i-1) printf("%s\n",s[j]);
    }
    return 0;
}
