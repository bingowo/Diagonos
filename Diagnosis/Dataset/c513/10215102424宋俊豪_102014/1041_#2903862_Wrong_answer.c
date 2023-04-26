#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int max=1,i=1,cnt=1;
    while(s[i]!='\0')
    {
        if(s[i]!=s[i-1])
            cnt++;
        else
        {
            if (cnt>max)
                max=cnt;
            cnt=1;
        }
        i++;
    }
    printf("%d",max);
    return 0;
}
