#include <stdio.h>
#include <string.h>

int charToInt(char ch)
{
    switch(ch)
    {
        case'I':return 1;
        case'V':return 5;
        case'X':return 10;
        case'L':return 50;
        case'C':return 100;
        case'D':return 500;
        case'M':return 1000;
        default:return 0;
    }

}
int romanToInt(char*s)
{
    int count=0;
    int sum=0;
    if(s==NULL)
        return 0;
    while(s[count]!='\0')
    {
        if(charToInt(s[count])<charToInt(s[count+1]))
        {
            sum=sum+charToInt(s[count+1])-charToInt(s[count]);
            count++;
        }
        else
            sum=sum+charToInt(s[count]);
        count++;
    }
    return sum;
}
int main()
{
    char s[100];
    gets(s);
    int answer;
    answer=romanToInt(s);
    printf("%d",answer);
    return 0;
}
