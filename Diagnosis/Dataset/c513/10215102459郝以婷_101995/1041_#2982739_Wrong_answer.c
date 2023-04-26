#include <stdio.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",&s);
    int i,len,count=1,max=0;
    len=strlen(s);
    for(i=1;i<len;i++)
    {
        if(s[i]!=s[i-1])
        {
            count++;
            if(i==len-1)
                max=count;
        }
        else
        {
            if(count>max)
                max=count;
            count=1;
        }
    }
    printf("%d",max);
    return 0;
}
