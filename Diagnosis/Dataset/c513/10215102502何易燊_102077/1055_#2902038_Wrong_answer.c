#include <stdio.h>
#include <string.h>

main()
{
    int table[128] = {};
    char *str = (char*)malloc(100001);
    scanf("%s",str);
    int max = 0, rec = 0;
    int pos = 0;
    for (int i=0;str[i];i++)
    {
        if (table[str[i]]!=0)
        {
            if (rec>max) max = rec;
            else pos = i;
            rec = 0;
            memset(table,0,sizeof(table));
        }
        else
        {
            rec++;
            table[str[i]]++;
        }
    }
    str[pos+max] = '\0';
    printf("%s\n",str+pos);
    return 0;
}