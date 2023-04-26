#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char str[100];
    scanf("%s",str);
    int i,j,flag0=0,flag1;
    for(i=0;i<strlen(str)-1;i++)
    {
        for(j=i,flag1=0;j<strlen(str)-1&&str[j]!=str[j+1];j++,flag1++);
        if(flag1>flag0) flag0=flag1;
    }
    printf("%d",flag0+1);
}
