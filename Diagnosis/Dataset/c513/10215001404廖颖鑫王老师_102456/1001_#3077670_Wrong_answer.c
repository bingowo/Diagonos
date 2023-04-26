#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char s[])
{
    int i,len=strlen(s),g;
    for(i=0;i<=len/2-1;i++)
    {
        g=s[i];
        s[i]=s[len-1];
        s[len-1]=g;
    }
}

void itob(int n,char s[100],int r)
{
    int flag,i;
    if(n<0)n=-n,flag=1;
    else flag=0;

    for(i=0;n>0;i++)
    {
        if(n%r<10)
        {
            s[i]=n%r+'0';
            n=n/r;
        }
        if(n%r>=10)
        {
            s[i]=n%r+'A'-10;
            n=n/r;
        }

        if(flag==1)s[i]='-',s[i+1]='\0';
        else s[i]='\0';
        swap(s);
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        char s[100];
        itob(n,s,r);
        printf("%s\n",s);
    }
    return 0;
}
