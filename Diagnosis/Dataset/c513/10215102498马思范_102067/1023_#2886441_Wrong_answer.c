#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void*b)
{
   char *c=*(char(*)[31])a;
   char *d=*(char(*)[31])b;
   if(num(c)==num(d))
        return strcmp(c,d);
   else return num(c)-num(d);
}
int num(char s[])
{
    int sum=0;
    int flag=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            sum=sum*10+s[i]-'0';
            flag=1;
    }
    if(flag==0)
        sum=-1;
    return sum;
}
int main()
{
    int i=0;
    char s[110][31];
    while(scanf("%s",s[i])!=EOF)
    {
        i++;
    }
    qsort(s,i,sizeof(s[0]),cmp);
    for(int r=0;r<i-1;r++)
    {
        printf("%s ",s[r]);
    }
    printf("%s",s[i-1]);
    return 0;
}