#include <stdio.h>
#include <string.h>
void itob(int n,int b,char *str)
{
    char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int j,i=100,sign=0;
    char buf[i+1];
    buf[100]='\0';
    if(n<0)
    {
        n=-n;
        sign=-1;
    }
    while(n!=0)
    {
        buf[--i]=s[n%b];
        n/=b;
    }
    for(j=0;(*(str+j)=buf[i])!='\0';j++,i++);
    if(sign==-1)
    {
        printf("-");
    }
}

int main()
{
    int T,N,R,i;
    char s[100];
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d\n",&N,&R);
        itob(N,R,s);
        printf("%s\n",s);
    }
    return 0;
}