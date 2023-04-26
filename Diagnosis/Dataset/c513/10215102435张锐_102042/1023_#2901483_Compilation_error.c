#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int nodigit(char s[])
{
    int len=strlen(s);int b=1;
    for(int i=0;i<len;i++)
    {
        if(isdigit(s[i])) {b=0;break;}
    }
    return b;
}
int num(char s[])
{
    int x=0;int i=0;
    for(;i<len;i++) {if(isdigit(s[i])) break;}
    for(;isdigit(s[i]);i++) {x=x*10+(s[i]-'0');}
    return x;
}
int cmp(const void *a,const void *b)
{
    char s1=*(char *)a,s2=*(char *)b;
    if(nodigit(s1)&&nodigit(s2)) return strcmp(s1,s2);
    else if(nodigit(s1)) return -1;
    else if(nodigit(s2)) return 1;
    else if(num(s1)==num(s2)) return strcmp(s1,s2);
    else if(num(s1)>num(s2)) return 1;
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
