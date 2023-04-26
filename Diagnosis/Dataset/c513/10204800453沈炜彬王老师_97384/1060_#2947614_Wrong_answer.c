#include <stdio.h>
#include <string.h>

int
main()
{
    char s[101] = {'\0'};
    unsigned long len;
    int count=0;
    int temp=0;
    char t;
    
    scanf("%s",s);
    len = strlen(s);
    for (int i=0; i<len; i++)
    {
        t = *(s+i);
        if (t<58 && t>48)
        {
            temp++;
        }
        else
        {
            count = count>temp?count:temp;
            temp = 0;
        }
    }
    count = count>temp?count:temp;
    printf("%d\n",count);
    
    return 0;
}