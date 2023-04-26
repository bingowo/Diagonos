#include<stdio.h>
#include<string.h>

int main()
{
    char s[51];
    int l,m=1,n=1;
    scanf("%s",&s);
    l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i+1]!=s[i])
        {
            n++;
        }
        else
        {
            if(n>m)
            {
               m=n;
            }
            n=1;
            continue;
        }
    }
    printf("%d",m);
    return 0;

}
