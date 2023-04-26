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
int turn(char s[],int n,int m)
{
    int b=0;
    for(int i=n;i<m;i++)
    {
        if(change(s[i])>=change(s[i+1]))
        {
            b=b+change(s[i]);
        }
        else
        {
            if(change(s[i])==1||change(s[i])==10||change(s[i])==100)
            {
                b=b-change(s[i])+change(s[i+1]);
                i=i+1;
            }
            else
            {
                b=b+change(s[i]);
            }
        }
    }
    return b;
}
int main()
{
    char s[50];
    scanf("%s",&s);
    int result=0;
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='(')
        {
            result=result+turn(s,0,i);
            int n=1;
            for(int j=i;j<l;j++)
            {
                
            }
        }
    }
    printf("%d",result);
    return 0;
}