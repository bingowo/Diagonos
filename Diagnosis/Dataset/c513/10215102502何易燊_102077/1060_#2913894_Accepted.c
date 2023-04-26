#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char s[101] = {};
    scanf("%s",s);
    int max = 0;
    for (int i=0;s[i];i++)
    {
        int record = 0;
        for (int j=i;s[j]>='0'&&s[j]<='9';j++)
        {
            if (s[i]=='0') continue;
            else record++;
        }
        if (record>max) {max = record; record = 0;}
    }
    printf("%d\n",max);
    return 0;
}