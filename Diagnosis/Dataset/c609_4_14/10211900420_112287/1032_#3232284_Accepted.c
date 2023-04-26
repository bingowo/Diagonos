#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,max,num;
    num=1;max=1;
    char x,s[51];
    scanf("%s",s);
    x=s[0];
    for(i=1;i<strlen(s);i++)
    {
        if(s[i]!=x)
        {
            num++;
            x=s[i];
        }
        else
        {
            if(max<num)
                max=num;
            num=1;
        }
        if(max<num)
            max=num;
    }
    printf("%d",max);
    return 0;
}
