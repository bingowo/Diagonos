#include <stdio.h>
#include <string.h>

main()
{
    char s[51];
    scanf("%s",s);
    int max = 0;
    int rec = 1;
    for (int i=0;s[i]&&s[i+1];i++)
    {
        if (s[i]==s[i+1])
        {
            if (rec>=max) max = rec;
            rec = 1;
        }
        else rec++;
    }
    if (rec>=max) max = rec;
    printf("%d\n",max);
    return 0;
}