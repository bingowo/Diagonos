#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char s[101]={0};
    gets(s);
    int i=0;
    int temp=0;
    int max=0;
    while(s[i])
    {
        while(s[i]=='0') i++;
        while(s[i]>='0'&&s[i]<='9') {temp++;i++;}
        if(temp>max) max=temp;
        temp=0;
        i++;
    }
    printf("%d\n",max);
    return 0;
}
