#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s[110];
    scanf("%s",s);
    int len=strlen(s),count=0,max=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]<='9'&&s[i]>'0') 
        {count++;
        if(max<count) max=count;}
        else count=0;
    }
    printf("%d",max);
    return 0;
}