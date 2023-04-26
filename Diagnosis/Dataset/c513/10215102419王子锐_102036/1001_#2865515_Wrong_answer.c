#include <stdio.h>
#include <string.h>
void itob(int n,char s[100],int b)
{
    const char *table="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sign=1;char *t=s;
    if(n<0)
    {
        sign=-1;n=-n;
    }
    do
    {
        *s++=*(table+(n%b));
        n=n/b;
    }while(n);
    if(sign==-1)*s++='-';
    *s='\0';
    reverse(t);
}

void reverse(char s[])
{
   int c;
   char *t;
   for(t=s+(strlen(s)-1);s<t;s++,t--){
       c=*s;
       *s=*t;
       *t=c;
   }
}

int main()
{
    int n,b;
    char s[100];
    scanf("%d%d",&n,&b);
    itob(n,s,b);
    printf("%s\n",s);
    return 0;
}