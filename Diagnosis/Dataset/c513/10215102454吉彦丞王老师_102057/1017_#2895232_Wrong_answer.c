#include<stdio.h>
#include<string.h>
int change(char a)
{
    if(a=='I')
    {
        return 1;
    }
    else if(a=='V')
    {
        return 5;
    }
    else if(a=='X')
    {
        return 10;
    }
    else if(a=='L')
    {
        return 50;
    }
    else if(a=='C')
    {
        return 100;
    }
    else if(a=='D')
    {
        return 500;
    }
    else
    {
        return 1000;
    }
}
int main()
{
    char s[50];
    scanf("%s",&s);
    int result=0;
    int l=strlen(s);
    for(int i=0;i<l-1;i++)
    {
        if(change(s[i])>=change(s[i+1]))
        {
            result=result+change(s[i]);
        }
    }
    printf("%d",result);
    return 0;
}