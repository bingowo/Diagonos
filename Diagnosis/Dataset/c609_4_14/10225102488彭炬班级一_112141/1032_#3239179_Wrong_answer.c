#include <stdio.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int len = strlen(s);
    int max = 1;
    int count = 1;
    for(int i = 0;i <= len;i++)
    {
        if(s[i]!=s[i+1])
            count++;
        else
        {
            count = 1;
            continue;
        }
        if(count > max)
            max = count;
    }
    printf("%d",max);
    return 0;
}
