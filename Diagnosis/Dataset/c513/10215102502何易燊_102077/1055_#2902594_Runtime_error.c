#include <stdio.h>
#include <string.h>

main()
{
    int table[128] = {};
    char *str = (char*)malloc(200000);
    scanf("%s",str);
    int max = 0, rec = 0;
    int i;
    char *pos;
    for (i=0;str[i];i++)
    {
        int j=i;
        while (table[str[j]]==0&&str[j])
        {
            table[str[j++]]++;
            rec++;
        }
        if (rec>max) {max = rec; pos = str+i;}
        rec = 0;
        memset(table,0,sizeof(table));
    }
    *(pos+max) = '\0';
    printf("%s\n",pos);
    return 0;
}