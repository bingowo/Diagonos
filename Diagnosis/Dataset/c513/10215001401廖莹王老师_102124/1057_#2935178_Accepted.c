#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}
void read(char c,char t[10000])
{
    int j=0;
    j=strlen(t);
    reverse(t);
    t[j]=c;t[j+1]='\0';
    reverse(t);

}
int main()
{
    char s[10000];
    char t[10000]={0};
    int i=0;
    scanf("%s",s);
    t[0]=toupper(s[0]);
    for(i=1;s[i];i++)
    {
        s[i]=toupper(s[i]);
        if(s[i]<t[0])t[i]=s[i];
        else {t[i]='\0';read(s[i],t);}

    }

    printf("%s",t);

    return 0;
}
