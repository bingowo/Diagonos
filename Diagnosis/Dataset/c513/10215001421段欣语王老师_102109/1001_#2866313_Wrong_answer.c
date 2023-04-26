#include <stdio.h>
#include <stdlib.h>

void backwards(char s[])
{
    int i,len=strlen(s),g;
    for(i=0;i<=len/2-1;i++)
    {
        g=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=g;
    }
}

void itob(int n,char s[100],int b)
{
    int i,point,g,d;
    if(n<0)
        point=1,n=-n;
    else point=0;
    for(i=0;n>0;i++)
    {
        if (n%b<10)s[i]='0'+n%b;
        else s[i]='A'+n%b-10;
        n=n/b;
    }
    s[i]='\0';
    if(point==1)
        s[i]='-',s[i+1]='\0';
    backwards(s);
}

int main()
{
    int N,R,T;
    char s[100];
    scanf("%d\n",&T);
    scanf("%d %d\n",&N,&R);
    itob(N,s,R);
    printf("%s\n",s);
    return 0;
}
