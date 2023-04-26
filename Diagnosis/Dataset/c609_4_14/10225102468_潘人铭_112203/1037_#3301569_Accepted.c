#include <stdio.h>
 #include <string.h>
 int main()
 {
    char s[1000005];
    scanf("%s", s);
    int len = strlen(s);
    int hash[128] = { 0 };
    int start = 0, end = 0, maxlen = 0, maxstart = 0;
    while (end < len)
   {
        char c = s[end];
        if (hash[c] && hash[c] - 1 >= start)
      {
       int curlen = end - start;
            if (curlen > maxlen)
           {
                maxlen = curlen;
                maxstart = start;
           }
            start = hash[c];
       }
        hash[c] = end + 1;
        ++end;
   }
    int curlen = end - start;
    if (curlen > maxlen)
   {
        maxlen = curlen;
        maxstart = start;
   }
    for (int i = maxstart; i < maxstart + maxlen; ++i)
   {
        putchar(s[i]);
   }
    putchar('\n');
    return 0;
 }