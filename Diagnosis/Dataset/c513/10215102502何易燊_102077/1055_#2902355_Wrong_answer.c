#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    int table[128] = {};
    char *str = (char*)malloc(100001);
    scanf("%s",str);
    int max = 0, rec = 0;
    int i;
    int pos = 0;
    for (i=0;str[i];i++)
    {
        if (table[str[i]]!=0)
        {
            if (rec>max) {max = rec; pos = i;}
            rec = 1;
            memset(table,0,sizeof(table));
            table[str[i]]++;
        }
        else
        {
            rec++;
            table[str[i]]++;
        }
    }
    if (rec>max) {max = rec; pos = i;}
    str[pos] = '\0';
    printf("%s\n",str+pos-max);
    system("pause");
    return 0;
}