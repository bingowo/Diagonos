#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[101] = {0};
    scanf("%s",s);

    int num = 0;
    int max = 0;
    int i = 0;
    while(i<strlen(s))
    {
        if(s[i]<'1' || s[i]>'9') i++;
        else
        {
            while(s[i]>='1' && s[i]<='9' && i<strlen(s))
            {
                num++;
                i++;
            }
            if(num>max)
            {
                max = num;
            }
            num = 0;
        }
    }
    printf("%d",max);
    return 0;
}
