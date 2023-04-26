#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 60

const char* s1="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void reverse(char* s)
{
    int i=0,j=strlen(s)-1;
    char tmp;
    for (i,j;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}

char* trans(int n,int r,char* s)
{
    int i;
    if (n>0)
    {
         for(i=0;n/r;i++)
        {
            s[i]=s1[n%r];
            n=n/r;
        }
        if (n!=0) s[i]=s1[n];
    }
    else
    {
        for(i=0;n/r;i++)
        {
            s[i]=s1[-n%r];
            n=n/r;
        }
        if (n!=0) s[i++]=s1[-n];
        s[i]='-';
    }

    return s;
}


int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int N,R;
        scanf("%d %d",&N,&R);
        char s[MAX]={0};
        char* ss=trans(N,R,s);
        reverse(ss);
        printf("%s\n",ss);

    }
    return 0;
}
