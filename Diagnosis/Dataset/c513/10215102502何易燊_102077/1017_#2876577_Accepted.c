#include <stdio.h>

main()
{
    int table[100] = {0};
    table['I'] = 1, table['V'] = 5, table['X'] = 10;
    table['L'] = 50, table['C'] = 100, table['D'] = 500, table['M'] = 1000;
    char s[1000];
    scanf("%s",s);
    long long array[1000] = {0};
    long long mul = 1;
    int index = 0;
    for (int i=0;s[i];i++)
    {
        if (s[i]=='(') mul *= 1000;
        else if (s[i]==')') mul /= 1000;
        else array[index++] = table[s[i]]*mul;
    }
    long long ans = 0;
    for (int i=0;i<index;i++)
    {
        if (array[i]>=array[i+1]) ans += array[i];
        else ans -= array[i];
    }
    printf("%lld\n",ans);
    return 0;
}