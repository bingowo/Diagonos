#include<stdio.h>
#include<string.h>
int main()
{
    int T,i,n=0,len,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        n=0;
        char s[501];
        char c,c0;
        printf("case #%d:\n",i);
        scanf("%s",s);
        c0=s[0];
        len=strlen(s);
        for(j=0;j<len;j++)
        {
            c=s[j];
            if(c==c0&&n<256)n++;
            else if(n==256)
            {
                printf("255%c",c0);
                n=2;
            }
            else
            {
                printf("%d%c",n,c0);
                c0=c;
                n=1;
            }
        }
        printf("%d%c\n",n,c0);
    }
    return 0;
}