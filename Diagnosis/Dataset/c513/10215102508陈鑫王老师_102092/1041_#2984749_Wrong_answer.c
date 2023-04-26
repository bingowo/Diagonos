#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int max=1,temp=1,len=strlen(s);
    for(int i=1;i<len;i++)
    {
        if(s[i]!=s[i-1])
        {
            temp++;

        }
        else
        {
            max=max>temp?max:temp;
            temp=1;
        }
    }
    printf("%d",max);
    return 0;

}
