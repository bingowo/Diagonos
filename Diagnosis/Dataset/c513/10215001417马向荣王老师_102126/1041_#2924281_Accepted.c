#include<stdio.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int j=0,i=1,m=0;
    for(;s[j]!='\0';j++)
    {
        if(s[j] == s[j+1] || s[j+1]=='\0')
        {
            if(m<i) m=i;
            i=1;
        }
        else i++;
    }
    printf("%d",m);
    return 0;
}