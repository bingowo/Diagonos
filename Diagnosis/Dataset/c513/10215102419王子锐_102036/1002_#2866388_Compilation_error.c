#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char s[max]；

    int n,b,m,a=0;
    char s[33];
    scanf("%d",&m);
    while(m>a){
    scanf("%d",&n);
    itob(n,s,b);
    printf("case #%d:\n%s",a,s);
    a+=1;
    }
    
    return 0;
}
void itob(int n,char s[100],int b)
{
    const char *table="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
    int n,b,m,a=0;
    char s[33];
    scanf("%d",&m);
    while(m>a){
    a+=1;
    scanf("%d%d",&n,&b);
    itob(n,s,b);
    printf("%s\n",s);
    }
    
    return 0;
}